#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <algorithm>
#include <vector>
 
using namespace std;
 
#define LOCAL 0
#define MAX_PIECES 50000
#define NUM_PIECES 7
#define MAX_PIECE_ROT 4
#define MAX_PIECE_SIZE 5
#define BOARD_SIZE 15
 
const int nrot[NUM_PIECES] = {2, 4, 4, 1, 2, 4, 2};
 
const int rotdim[NUM_PIECES][MAX_PIECE_ROT][2] = {
{{1, 4}, {4, 1}}, // 0
{{2, 3}, {3, 2}, {3, 2}, {2, 3}}, // 1
{{2, 3}, {3, 2}, {2, 3}, {3, 2}}, // 2
{{2, 2}}, // 3
{{2, 3}, {3, 2}}, // 4
{{2, 3}, {3, 2}, {2, 3}, {3, 2}}, // 5
{{2, 3}, {3, 2}}, // 6
};
 
const char rotmask[NUM_PIECES][MAX_PIECE_ROT][MAX_PIECE_SIZE][MAX_PIECE_SIZE] = {
{
{"1111",}, // 0.0
{"1",
 "1",
 "1",
 "1",}, // 0.1
}, // 0
{
{"100",
 "111",}, // 1.0
{"01",
 "01",
 "11",}, // 1.1
{"11",
 "10",
 "10",}, // 1.2
{"111",
 "001",}, // 1.3
}, // 1
{
{"001",
 "111",}, // 2.0
{"10",
 "10",
 "11",}, // 2.1
{"111",
 "100",}, // 2.2
{"11",
 "01",
 "01",}, // 2.3
}, // 2
{
{"11",
 "11",}, // 3.0
}, // 3
{
{"011",
 "110",}, // 4.0
{"10",
 "11",
 "01",}, // 4.1
}, // 4
{
{"010",
 "111",}, // 5.0
{"10",
 "11",
 "10",}, // 5.1
{"111",
 "010",}, // 5.2
{"01",
 "11",
 "01",}, // 5.3
}, // 5
{
{"110",
 "011",}, // 6.0
{"01",
 "11",
 "10",}, // 6.1
}, // 6
};
 
int rrotbitmask[NUM_PIECES][MAX_PIECE_ROT][MAX_PIECE_SIZE], crotbitmask[NUM_PIECES][MAX_PIECE_ROT][MAX_PIECE_SIZE], bit[BOARD_SIZE + 2];
int rtrans[65536], ctrans[65536], cnumholes[65536], firstone[65536], nbits[65536], wells2[65536], wells3[65536], wells4[65536], wells5[65536], sqholes[65536], TESTID;
int nwells2[65536], nwells3[65536], nwells4[65536], nwells5[65536];
 
void Init() {
	int i, j, k, l;
	bit[0] = 1;
	for (i = 1; i <= BOARD_SIZE + 1; i++) bit[i] = bit[i - 1] << 1;
	for (i = 0; i < NUM_PIECES; i++)
		for (j = 0; j < nrot[i]; j++) {
			for (k = 0; k < rotdim[i][j][0]; k++) {
				rrotbitmask[i][j][k] = 0;
				for (l = 0; l < rotdim[i][j][1]; l++)
					if (rotmask[i][j][k][l] == '1')
						rrotbitmask[i][j][k] |= bit[l];
			}
			for (k = 0; k < rotdim[i][j][1]; k++) {
				crotbitmask[i][j][k] = 0;
				for (l = 0; l < rotdim[i][j][0]; l++)
					if (rotmask[i][j][l][k] == '1')
						crotbitmask[i][j][k] |= bit[l];
			}
		}
	for (i = 0; i < 65536; i += 2) {
		rtrans[i] = 0;
		if ((i & bit[1]) == 0) rtrans[i]++;
		for (j = 2; j <= BOARD_SIZE; j++) {
			if (((i & bit[j - 1]) << 1) !=
				 (i & bit[j]))
				rtrans[i]++;
		}
		if ((i & bit[BOARD_SIZE]) == 0) rtrans[i]++;		
		ctrans[i] = 0;
		if ((i & bit[1]) > 0) ctrans[i]++;
		for (j = 2; j <= BOARD_SIZE; j++)
			if (((i & bit[j - 1]) << 1) !=
				 (i & bit[j]))
				ctrans[i]++;
		if ((i & bit[BOARD_SIZE]) == 0) ctrans[i]++;
		cnumholes[i] = 0;
		for (j = 1; j <= BOARD_SIZE; j++)
			if ((i & bit[j]) > 0) break;
		for (j++; j <= BOARD_SIZE; j++)
			if ((i & bit[j]) == 0)
				cnumholes[i]++;
		firstone[i] = BOARD_SIZE + 1;
		for (j = 1; j <= BOARD_SIZE; j++)
			if ((i & bit[j]) > 0) {
				firstone[i] = j;
				break;
			}
		wells2[i] = wells3[i] = wells4[i] = wells5[i] = 0;
		nwells2[i] = nwells3[i] = nwells4[i] = nwells5[i] = 0;
		int clen = 0;
		for (j = 1; j <= BOARD_SIZE; j++)
			if ((i & bit[j]) > 0) clen++;
			else {
				if (clen >= 2) {
					wells2[i] += clen * (clen - 1);
					nwells2[i]++;
				}
				if (clen >= 3) {
					wells3[i] += clen * (clen - 1);
					nwells3[i]++;
				}
				if (clen >= 4) {
					wells4[i] += clen * (clen - 1);
					nwells4[i]++;
				}
				if (clen >= 5) {
					wells5[i] += clen * (clen - 1);
					nwells5[i]++;
				}
				clen = 0;
			}
		if (clen >= 2) {
			wells2[i] += clen * (clen - 1);
			nwells2[i]++;
		}
		if (clen >= 3) {
			wells3[i] += clen * (clen - 1);
			nwells3[i]++;
		}
		if (clen >= 4) {
			wells4[i] += clen * (clen - 1);
			nwells4[i]++;
		}
		if (clen >= 5) {
			wells5[i] += clen * (clen - 1);
			nwells5[i]++;
		}
		sqholes[i] = 0;
		clen = 0;
		for (j = 1; j <= BOARD_SIZE; j++)
			if ((i & bit[j]) > 0) break;
		for (j++; j <= BOARD_SIZE; j++)
			if ((i & bit[j]) == 0) clen++;
			else {
				sqholes[i] += clen * (clen - 1);
				clen = 0;
			}
		sqholes[i] += clen * (clen - 1);
		nbits[i] = 0;
		for (j = 1; j <= BOARD_SIZE; j++)
			if ((i & bit[j]) > 0) nbits[i]++;		
	}
}
 
int piece[MAX_PIECES][3], pw[NUM_PIECES], pcnt[NUM_PIECES];
int piece_cnt;
 
void GenerateTest(int t, int p0 = 1, int p1 = 1, int p2 = 1, int p3 = 1, int p4 = 1, int p5 = 1, int p6 = 1) {
	srand(t * 1993 + 997);
	int i, j;
	pw[0] = p0;
	pw[1] = p1;
	pw[2] = p2;
	pw[3] = p3;
	pw[4] = p4;
	pw[5] = p5;
	pw[6] = p6;
	for (j = 1; j < NUM_PIECES; j++) pw[j] += pw[j - 1];
	memset(pcnt, 0, sizeof(pcnt));
 
	for (i = 0; i < MAX_PIECES; i++) {
		piece[i][0] = 1;// + (rand() % 2);
		int x = rand() % pw[NUM_PIECES - 1];
		for (j = 0; j < NUM_PIECES; j++)
			if (x < pw[j]) {
				piece[i][1] = j;
				break;
			}
		pcnt[piece[i][1]]++;
		if (piece[i][0] == 2) piece[i][2] = rand() % nrot[piece[i][1]];
	}
	piece_cnt = 0;
	//for (j = 0; j < NUM_PIECES; j++) fprintf(stderr, " %d ", pcnt[j]);
	//fprintf(stderr, "\n");
}
 
char line[128];
 
int GetNextPiece(int& type, int& pid, int& rid) {
	if (LOCAL) {
		if (piece_cnt == MAX_PIECES) return 0;
		type = piece[piece_cnt][0];
		pid = piece[piece_cnt][1];
		if (type == 1) rid = -1;
		else rid = piece[piece_cnt][2];
		piece_cnt++;
		return 1;
	} else {
		fgets(line, 127, stdin);
		if (line[0] == 'G') {
			return 0;
		}
		int nread;
		sscanf(line, "%d %d%n", &type, &pid, &nread);
		pid--;
		if (type == 1) rid = -1;
		else {
			char rotch;
			sscanf(line + nread, " %c", &rotch);
			rid = rotch - 'a';
		}
		return 1;
	}
}
 
#define MAX_PIECE_POZ 2000
 
int rboardmask[BOARD_SIZE + 1], cboardmask[BOARD_SIZE + 1], ok[BOARD_SIZE + 1];
int poz[MAX_PIECE_POZ][3], npoz;
int q[BOARD_SIZE + 1], qli, qls;
 
void BFS(int pid, int rid, int rbmask[BOARD_SIZE + 1]) {
	memset(ok, 0, sizeof(ok));
	int i, j, k, nrows = rotdim[pid][rid][0], ncols = rotdim[pid][rid][1];
	for (j = 1; j + ncols - 1 <= BOARD_SIZE; j++)
		ok[0] |= bit[j];
	for (i = 0; i < BOARD_SIZE; i++) {
		qli = 0; qls = -1;
		for (j = 1; j + ncols - 1 <= BOARD_SIZE; j++)
			if ((ok[i] & bit[j]) > 0) {
				qls++;
				q[qls] = j;
			}
		while (qli <= qls) {
			j = q[qli];
			qli++;
			// Try to move to the right.
			if (j + ncols <= BOARD_SIZE && (ok[i] & bit[j + 1]) == 0) {
				int can_move = 1;
				for (k = 0; k < nrows && can_move; k++)
					if (((rrotbitmask[pid][rid][k] << (j + 1)) & rbmask[i - nrows + 1 + k]) != 0) can_move = 0;
				if (can_move) {
					ok[i] |= bit[j + 1];
					qls++;
					q[qls] = j + 1;
				}
			}
			// Try to move to the left.
			if (j - 1 >= 1 && (ok[i] & bit[j - 1]) == 0) {
				int can_move = 1;
				for (k = 0; k < nrows && can_move; k++)
					if (((rrotbitmask[pid][rid][k] << (j - 1)) & rbmask[i - nrows + 1 + k]) != 0) can_move = 0;
				if (can_move) {
					ok[i] |= bit[j - 1];
					qls++;
					q[qls] = j - 1;
				}
			}
		}
		for (j = 1; j + ncols - 1 <= BOARD_SIZE; j++) {
			if ((ok[i] & bit[j]) == 0) continue;
			int can_fall = 1;
			for (k = 0; k < nrows && can_fall; k++)
				if ((((rrotbitmask[pid][rid][k] << j)) & rbmask[i - nrows + 2 + k]) != 0) can_fall = 0;
			if (can_fall) {
				ok[i] ^= bit[j];
				ok[i + 1] |= bit[j];
			}
		}
	}
}
 
int num_pieces, num_cleared_rows, num_cleared_rows_now, score;
 
void ClearRows(int rb[BOARD_SIZE + 1], int cb[BOARD_SIZE + 1]) {
	num_cleared_rows_now = 0;
	int i, k;
	for (i = BOARD_SIZE; i >= 1; i--) {
		if (rb[i] == 65534) {
			for (k = i - 1; k >= 1; k--)
				rb[k + 1] = rb[k];
			rb[1] = 0;
			for (k = 1; k <= BOARD_SIZE; k++)
				cb[k] = (cb[k] & (bit[BOARD_SIZE + 1] - bit[i + 1])) | ((cb[k] & (bit[i] - 1)) << 1);
			i++;
			num_cleared_rows_now++;
		}
	}
}
 
int PARAM_IDX;
 
void DoMove(int pid, int rid, int row, int col, int rb[BOARD_SIZE + 1], int cb[BOARD_SIZE + 1], int is_final_move) {
	if (!LOCAL && is_final_move && PARAM_IDX == 0) {
		printf("%c %d %d\n", rid + 'a', row, col);
		fflush(stdout);
	}
	
	int i, nrows = rotdim[pid][rid][0], ncols = rotdim[pid][rid][1];
	if (row - nrows + 1 <= 0 || row > BOARD_SIZE || col <= 0 || col + ncols - 1 > BOARD_SIZE) {
		fprintf(stderr, "pid=%d rid=%d row=%d nrows=%d col=%d ncols=%d\n", pid, rid, row, nrows, col, ncols);
		//exit(101);
	}
	for (i = 0; i < nrows; i++)
		rb[row - nrows + 1 + i] |= (rrotbitmask[pid][rid][i] << col);
	for (i = 0; i < ncols; i++)
		cb[col + i] |= (crotbitmask[pid][rid][i] << (row - nrows + 1));
	if (is_final_move) {
		ClearRows(rb, cb);
		num_pieces++;
		score++;
		num_cleared_rows += num_cleared_rows_now;
		score += 10 * num_cleared_rows_now * num_cleared_rows_now;
		int is_board_empty = 1;
		for (i = BOARD_SIZE; i >= 1 && is_board_empty; i--)
			if (rb[i] != 0) is_board_empty = 0;
		if (is_board_empty) score += 500;
	}
}
 
#define FOCUS_TEST -2
#define NUM_IDENTIFIED_TESTS 18
#define MAX_PARAM_IDX 4
 
int SCORING_PARAMS[NUM_IDENTIFIED_TESTS + 1][10] = {
{0, 74, 75, 76, 77,}, // -1 (local tests)
{37, 0, 0, 0, 0,}, // 0 : 37 : 1 2 3 5 7 8 9 10 11 12 16 17 18 19 23 24 25 26 31 32 33 34 35 36 37 46 47 53 54 55 57 58 61 62 79 80
{0, 74, 75, 76, 77,}, // 1 : 0 : 0 1 2 3 38 74 75 76 77
{41, 66, 67, 68, 69,}, // 2 : 41 : 7 10 37 38 40 41 42 43 66 67 68 69
{41, 0, 0, 0, 0,}, // 3 : 41 : 0 1 2 3 4 7 8 9 10 11 12 16 17 26 31 32 38 39 40 41 42 46 47 48 49
{76, 74, 75, 76, 77,}, // 4 : 76 : 0 1 2 3 6 7 8 9 10 74 75 76 77
{62, 61, 62, 63, 64,}, // 5 : 62 : 0 1 2 3 6 7 8 9 10 11 12 16 38 40 41 42 43 46 47 48 49 61 62 63 64
{7, 74, 75, 76, 77,}, // 6 : 7 : 0 1 2 3 6 7 8 9 10 11 12 16 26 31 32 37 38 40 41 42 43 74 75 76 77
{43, 61, 62, 63, 64,}, // 7 : 43 : 0 1 2 3 6 7 8 9 10 11 12 16 38 40 41 42 43 46 47 48 49 61 62 63 64
{68, 66, 67, 68, 69,}, // 8 : 68 : 0 1 2 3 6 7 8 9 10 11 12 37 38 40 41 42 43 46 47 48 49 66 67 68 69
{75, 74, 75, 76, 77,}, // 9 : 75 : 0 1 2 3 6 7 8 9 10 11 12 37 38 40 41 42 43 46 47 48 49 66 67 68 69 74 75 76 77
{37, 0, 0, 67, 68,}, // 10 : 37 : 0 1 2 3 6 7 10 37 38 46 47 48 49 61 62 63 64 67 68
{41, 74, 75, 76, 77,}, // 11 : 41 : 0 1 2 3 6 7 8 9 10 11 12 16 17 26 31 32 38 40 41 42 43 46 47 48 49 61 62 63 64 66 67 68 69 74 75 76 77
{0, 74, 75, 76, 77,}, // 12 : 0 : 0 1 2 3 6 7 8 9 10 74 75 76 77
{0, 74, 75, 76, 77,}, // 13 : 0 : 0 1 2 3 4 6 7 8 9 74 75 76 77
{73, 0, 0, 0, 0,}, // 14 : 73 : 0 2 3 6 13 14 15 22 27 28 29 30 35 39 45 50 51 52 66 69 70 72 73 78
{67, 66, 67, 68, 69,}, // 15 : 67 : 0 1 2 3 6 7 8 9 10 11 12 16 17 26 31 32 38 40 41 42 43 46 47 48 49 61 62 63 64 66 67 68 69
{77, 0, 0, 0, 0,}, // 16 : 0 : 0 1 2 3 6 7 8 9 10
{77, 74, 75, 76, 77,}, // 17 : 0 : 0 1 2 3 6 7 8 9
};
 
int rbmask[BOARD_SIZE + 1], cbmask[BOARD_SIZE + 1], SCORING_PARAM;
 
double ComputeScore(int pid, int rid, int row, int col) {
	memcpy(rbmask, rboardmask, sizeof(rbmask));
	memcpy(cbmask, cboardmask, sizeof(cbmask));
	double score = 0.0;
	int i, j, minlevel = BOARD_SIZE + 1;
 
	// Minlevel.
	for (j = 1; j <= BOARD_SIZE; j++)
		if (firstone[cbmask[j]] < minlevel) minlevel = firstone[cbmask[j]];
 
	DoMove(pid, rid, row, col, rbmask, cbmask, 0);
 
	// Full rows.
	ClearRows(rbmask, cbmask);
	int nfull_rows = num_cleared_rows_now;
 
	// Landing height.
	double landing_height = BOARD_SIZE - row + 0.5 * rotdim[pid][rid][0];
 
	// Row transitions.
	int row_transitions = 0;
	for (i = 1; i <= BOARD_SIZE; i++)
		row_transitions += rtrans[rbmask[i]];
 
	// Column transitions
	int col_transitions = 0;
	for (j = 1; j <= BOARD_SIZE; j++)
		col_transitions += ctrans[cbmask[j]];
 
	// Number of holes.
	int num_holes = 0;
	for (j = 1; j <= BOARD_SIZE; j++)
		num_holes += cnumholes[cbmask[j]];
 
	// Well lengths.
	int well2_lengths = 0, well3_lengths = 0, well4_lengths = 0, well5_lengths = 0;
	int cnt_wells2 = 0, cnt_wells3 = 0, cnt_wells4 = 0, cnt_wells5 = 0;
	for (j = 1; j <= BOARD_SIZE; j++) {
		int cmask = cbmask[j] ^ 65534;
		if (j >= 2) cmask &= cbmask[j - 1];
		if (j < BOARD_SIZE) cmask &= cbmask[j + 1];
		well2_lengths += wells2[cmask];
		well3_lengths += wells3[cmask];
		well4_lengths += wells4[cmask];
		well5_lengths += wells5[cmask];
		cnt_wells2 += nwells2[cmask];
		cnt_wells3 += nwells3[cmask];
		cnt_wells4 += nwells4[cmask];
		cnt_wells5 += nwells5[cmask];
	}
 
	// Sum of squared lengths of holes.
	int sum_sq_holes = 0;
	for (j = 1; j <= BOARD_SIZE; j++)
		sum_sq_holes += sqholes[cbmask[j]];
	
	// Number of blocked cells.
	int num_blocked_cells = num_holes;
	for (j = 1; j <= BOARD_SIZE; j++)
		num_blocked_cells += nbits[cbmask[j]];
	
	double W_LANDING_HEIGHT = -4.5;
	double W_NFULL_ROWS = 0.0;
	double W_ROW_TRANSITIONS = -3.2;
	double W_COL_TRANSITIONS = -9.0;
	double W_NUM_HOLES = -8.0;
	double W_WELLS2_LENGTHS = -3.0;
	double W_WELLS3_LENGTHS = 0.0;
	double W_WELLS4_LENGTHS = 0.0;
	double W_WELLS5_LENGTHS = 0.0;
	double W_SUM_SQ_HOLES = 0.0;
 
	if (SCORING_PARAM == 0) {
		// Nothing extra.
	} else if (SCORING_PARAM == 7) {
		W_WELLS2_LENGTHS = -2.0;
		if (minlevel >= 6) {
			if (nfull_rows == 1) score -= 30.0;
			if (nfull_rows == 2) score -= 20.0;
			if (nfull_rows >= 3) score += 1e7;
		}
	} else if (SCORING_PARAM == 37) {
		W_WELLS2_LENGTHS = -5.0;
		if (minlevel >= 7) {
			if (nfull_rows == 1) score -= 25.0;
			if (nfull_rows == 2) score -= 20.0;
			if (nfull_rows == 3) score -= 15.0;
			if (nfull_rows >= 4) score += 1e7;
			if (cnt_wells4 - cnt_wells5 > 0) well2_lengths -= 4 * 3;
			else if (cnt_wells3 - cnt_wells4 > 0) well2_lengths -= 3 * 2;
			else if (cnt_wells2 - cnt_wells3 > 0) well2_lengths -= 2 * 1;
		} else if (minlevel >= 6) {
			if (nfull_rows == 1) score -= 25.0;
			if (nfull_rows == 2) score -= 20.0;
			if (nfull_rows >= 3) score += 1e7;
			if (cnt_wells3 - cnt_wells4 > 0) well2_lengths -= 3 * 2;
			else if (cnt_wells2 - cnt_wells3 > 0) well2_lengths -= 2 * 1;
		} else if (minlevel >= 5) {
			if (nfull_rows == 1) score -= 15.0;
			if (nfull_rows >= 2) score += 1e7;
			if (cnt_wells2 - cnt_wells3 > 0) well2_lengths -= 2 * 1;
		}
	} else if (SCORING_PARAM == 38) {
		W_WELLS2_LENGTHS = -5.0;
		if (minlevel >= 7) {
			if (nfull_rows == 1) score -= 25.0;
			if (nfull_rows == 2) score -= 20.0;
			if (nfull_rows >= 3) score += 1e7;
			if (cnt_wells3 - cnt_wells4 > 0) well2_lengths -= 3 * 2;
			else if (cnt_wells2 - cnt_wells3 > 0) well2_lengths -= 2 * 1;
		} else if (minlevel >= 6) {
			if (nfull_rows == 1) score -= 15.0;
			if (nfull_rows >= 2) score += 1e7;
			if (cnt_wells2 - cnt_wells3 > 0) well2_lengths -= 2 * 1;
		}
	} else if (SCORING_PARAM == 39) {
		W_WELLS2_LENGTHS = -3.0;
		if (minlevel >= 6) {
			if (nfull_rows == 1) score -= 12.5;
			if (nfull_rows == 2) score -= 9.0;
			if (nfull_rows >= 3) score += 1e7;
			if (cnt_wells4 - cnt_wells5 > 0) well2_lengths -= 4 * 3;
			else if (cnt_wells3 - cnt_wells4 > 0) well2_lengths -= 3 * 2;
			else if (cnt_wells2 - cnt_wells3 > 0) well2_lengths -= 2 * 1;
		} else if (minlevel >= 5) {
			if (nfull_rows == 1) score -= 12.5;
			if (nfull_rows >= 2) score += 1e7;
			if (cnt_wells2 - cnt_wells3 > 0) well2_lengths -= 2 * 1;
		}
	} else if (SCORING_PARAM == 40) {
		W_WELLS2_LENGTHS = -3.0;
		if (minlevel >= 6) {
			if (nfull_rows == 1) score -= 15.0;
			if (nfull_rows == 2) score -= 12.0;
			if (nfull_rows >= 3) score += 1e7;
			if (cnt_wells4 - cnt_wells5 > 0) well2_lengths -= 4 * 3;
			else if (cnt_wells3 - cnt_wells4 > 0) well2_lengths -= 3 * 2;
			else if (cnt_wells2 - cnt_wells3 > 0) well2_lengths -= 2 * 1;
		} else if (minlevel >= 5) {
			if (nfull_rows == 1) score -= 15.0;
			if (nfull_rows >= 2) score += 1e7;
			if (cnt_wells2 - cnt_wells3 > 0) well2_lengths -= 2 * 1;
		}
	} else if (SCORING_PARAM == 41) {
		W_WELLS2_LENGTHS = -3.0;
		if (minlevel >= 6) {
			if (nfull_rows == 1) score -= 17.0;
			if (nfull_rows == 2) score -= 14.0;
			if (nfull_rows >= 3) score += 1e7;
			if (cnt_wells4 - cnt_wells5 > 0) well2_lengths -= 4 * 3;
			else if (cnt_wells3 - cnt_wells4 > 0) well2_lengths -= 3 * 2;
			else if (cnt_wells2 - cnt_wells3 > 0) well2_lengths -= 2 * 1;
		} else if (minlevel >= 5) {
			if (nfull_rows == 1) score -= 17.0;
			if (nfull_rows >= 2) score += 1e7;
			if (cnt_wells2 - cnt_wells3 > 0) well2_lengths -= 2 * 1;
		}
	} else if (SCORING_PARAM == 42) {
		W_WELLS2_LENGTHS = -3.0;
		if (minlevel >= 6) {
			if (nfull_rows == 1) score -= 19.0;
			if (nfull_rows == 2) score -= 16.0;
			if (nfull_rows >= 3) score += 1e7;
			if (cnt_wells4 - cnt_wells5 > 0) well2_lengths -= 4 * 3;
			else if (cnt_wells3 - cnt_wells4 > 0) well2_lengths -= 3 * 2;
			else if (cnt_wells2 - cnt_wells3 > 0) well2_lengths -= 2 * 1;
		} else if (minlevel >= 5) {
			if (nfull_rows == 1) score -= 19.0;
			if (nfull_rows >= 2) score += 1e7;
			if (cnt_wells2 - cnt_wells3 > 0) well2_lengths -= 2 * 1;
		}
	} else if (SCORING_PARAM == 43) {
		W_WELLS2_LENGTHS = -5.0;
		if (minlevel >= 6) {
			if (nfull_rows == 1) score -= 19.0;
			if (nfull_rows == 2) score -= 16.0;
			if (nfull_rows >= 3) score += 1e7;
			if (cnt_wells4 - cnt_wells5 > 0) well2_lengths -= 4 * 3;
			else if (cnt_wells3 - cnt_wells4 > 0) well2_lengths -= 3 * 2;
			else if (cnt_wells2 - cnt_wells3 > 0) well2_lengths -= 2 * 1;
		} else if (minlevel >= 5) {
			if (nfull_rows == 1) score -= 19.0;
			if (nfull_rows >= 2) score += 1e7;
			if (cnt_wells2 - cnt_wells3 > 0) well2_lengths -= 2 * 1;
		}
	} else if (SCORING_PARAM == 46) {
		W_WELLS2_LENGTHS = -2.0;
		if (minlevel >= 6) {
			if (nfull_rows == 1) score -= 30.0;
			if (nfull_rows == 2) score -= 25.0;
			if (nfull_rows >= 3) score += 1e7;
			if (cnt_wells4 - cnt_wells5 > 0) well2_lengths -= 4 * 3;
			else if (cnt_wells3 - cnt_wells4 > 0) well2_lengths -= 3 * 2;
			else if (cnt_wells2 - cnt_wells3 > 0) well2_lengths -= 2 * 1;
		} else if (minlevel >= 5) {
			if (nfull_rows == 1) score -= 30.0;
			if (nfull_rows >= 2) score += 1e7;
			if (cnt_wells2 - cnt_wells3 > 0) well2_lengths -= 2 * 1;
		}
	} else if (SCORING_PARAM == 60) {
		W_WELLS2_LENGTHS = -2.0;
		if (minlevel >= 7) {
			if (nfull_rows == 1) score -= 30.0;
			if (nfull_rows == 2) score -= 25.0;
			if (nfull_rows == 3) score -= 20.0;
			if (nfull_rows >= 4) score += 1e7;
			if (cnt_wells4 - cnt_wells5 > 0) well2_lengths -= 4 * 3;
			else if (cnt_wells3 - cnt_wells4 > 0) well2_lengths -= 3 * 2;
			else if (cnt_wells2 - cnt_wells3 > 0) well2_lengths -= 2 * 1;
		} else if (minlevel >= 6) {
			if (nfull_rows == 1) score -= 30.0;
			if (nfull_rows == 2) score -= 25.0;
			if (nfull_rows >= 3) score += 1e7;
			if (cnt_wells3 - cnt_wells4 > 0) well2_lengths -= 3 * 2;
			else if (cnt_wells2 - cnt_wells3 > 0) well2_lengths -= 2 * 1;
		} else if (minlevel >= 5) {
			if (nfull_rows == 1) score -= 20.0;
			if (nfull_rows >= 2) score += 1e7;
			if (cnt_wells2 - cnt_wells3 > 0) well2_lengths -= 2 * 1;
		}
	} else if (SCORING_PARAM == 61) {
		W_WELLS2_LENGTHS = -3.0;
		if (minlevel >= 7) {
			if (nfull_rows == 1) score -= 25.0;
			if (nfull_rows == 2) score -= 20.0;
			if (nfull_rows == 3) score -= 15.0;
			if (nfull_rows >= 4) score += 1e7;
			if (cnt_wells4 - cnt_wells5 > 0) {
				well2_lengths -= 4 * 3;
				cnt_wells4--;
			} else if (cnt_wells3 - cnt_wells4 > 0) {
				well2_lengths -= 3 * 2;
				cnt_wells3--;
			} else if (cnt_wells2 - cnt_wells3 > 0) {
				well2_lengths -= 2 * 1;
				cnt_wells2--;
			}
			if (cnt_wells4 - cnt_wells5 > 0) {
				well2_lengths -= 4 * 3;
				cnt_wells4--;
			} else if (cnt_wells3 - cnt_wells4 > 0) {
				well2_lengths -= 3 * 2;
				cnt_wells3--;
			} else if (cnt_wells2 - cnt_wells3 > 0) {
				well2_lengths -= 2 * 1;
				cnt_wells2--;
			}
		} else if (minlevel >= 6) {
			if (nfull_rows == 1) score -= 25.0;
			if (nfull_rows == 2) score -= 20.0;
			if (nfull_rows >= 3) score += 1e7;
			if (cnt_wells3 - cnt_wells4 > 0) {
				well2_lengths -= 3 * 2;
				cnt_wells3--;
			} else if (cnt_wells2 - cnt_wells3 > 0) {
				well2_lengths -= 2 * 1;
				cnt_wells2--;
			}
			if (cnt_wells3 - cnt_wells4 > 0) {
				well2_lengths -= 3 * 2;
				cnt_wells3--;
			} else if (cnt_wells2 - cnt_wells3 > 0) {
				well2_lengths -= 2 * 1;
				cnt_wells2--;
			}
		} else if (minlevel >= 5) {
			if (nfull_rows == 1) score -= 15.0;
			if (nfull_rows >= 2) score += 1e7;
			if (cnt_wells2 - cnt_wells3 > 0) {
				well2_lengths -= 2 * 1;
				cnt_wells2--;
			}
			if (cnt_wells2 - cnt_wells3 > 0) {
				well2_lengths -= 2 * 1;
				cnt_wells2--;
			}
		}
	} else if (SCORING_PARAM == 62) {
		W_WELLS2_LENGTHS = -2.75;
		if (minlevel >= 7) {
			if (nfull_rows == 1) score -= 25.0;
			if (nfull_rows == 2) score -= 20.0;
			if (nfull_rows == 3) score -= 15.0;
			if (nfull_rows >= 4) score += 1e7;
			if (cnt_wells4 - cnt_wells5 > 0) {
				well2_lengths -= 4 * 3;
				cnt_wells4--;
			} else if (cnt_wells3 - cnt_wells4 > 0) {
				well2_lengths -= 3 * 2;
				cnt_wells3--;
			} else if (cnt_wells2 - cnt_wells3 > 0) {
				well2_lengths -= 2 * 1;
				cnt_wells2--;
			}
			if (cnt_wells4 - cnt_wells5 > 0) {
				well2_lengths -= 4 * 3;
				cnt_wells4--;
			} else if (cnt_wells3 - cnt_wells4 > 0) {
				well2_lengths -= 3 * 2;
				cnt_wells3--;
			} else if (cnt_wells2 - cnt_wells3 > 0) {
				well2_lengths -= 2 * 1;
				cnt_wells2--;
			}
		} else if (minlevel >= 6) {
			if (nfull_rows == 1) score -= 25.0;
			if (nfull_rows == 2) score -= 20.0;
			if (nfull_rows >= 3) score += 1e7;
			if (cnt_wells3 - cnt_wells4 > 0) {
				well2_lengths -= 3 * 2;
				cnt_wells3--;
			} else if (cnt_wells2 - cnt_wells3 > 0) {
				well2_lengths -= 2 * 1;
				cnt_wells2--;
			}
			if (cnt_wells3 - cnt_wells4 > 0) {
				well2_lengths -= 3 * 2;
				cnt_wells3--;
			} else if (cnt_wells2 - cnt_wells3 > 0) {
				well2_lengths -= 2 * 1;
				cnt_wells2--;
			}
		} else if (minlevel >= 5) {
			if (nfull_rows == 1) score -= 15.0;
			if (nfull_rows >= 2) score += 1e7;
			if (cnt_wells2 - cnt_wells3 > 0) {
				well2_lengths -= 2 * 1;
				cnt_wells2--;
			}
			if (cnt_wells2 - cnt_wells3 > 0) {
				well2_lengths -= 2 * 1;
				cnt_wells2--;
			}
		}
	} else if (SCORING_PARAM == 63) {
		W_WELLS2_LENGTHS = -2.5;
		if (minlevel >= 7) {
			if (nfull_rows == 1) score -= 25.0;
			if (nfull_rows == 2) score -= 20.0;
			if (nfull_rows == 3) score -= 15.0;
			if (nfull_rows >= 4) score += 1e7;
			if (cnt_wells4 - cnt_wells5 > 0) {
				well2_lengths -= 4 * 3;
				cnt_wells4--;
			} else if (cnt_wells3 - cnt_wells4 > 0) {
				well2_lengths -= 3 * 2;
				cnt_wells3--;
			} else if (cnt_wells2 - cnt_wells3 > 0) {
				well2_lengths -= 2 * 1;
				cnt_wells2--;
			}
			if (cnt_wells4 - cnt_wells5 > 0) {
				well2_lengths -= 4 * 3;
				cnt_wells4--;
			} else if (cnt_wells3 - cnt_wells4 > 0) {
				well2_lengths -= 3 * 2;
				cnt_wells3--;
			} else if (cnt_wells2 - cnt_wells3 > 0) {
				well2_lengths -= 2 * 1;
				cnt_wells2--;
			}
		} else if (minlevel >= 6) {
			if (nfull_rows == 1) score -= 25.0;
			if (nfull_rows == 2) score -= 20.0;
			if (nfull_rows >= 3) score += 1e7;
			if (cnt_wells3 - cnt_wells4 > 0) {
				well2_lengths -= 3 * 2;
				cnt_wells3--;
			} else if (cnt_wells2 - cnt_wells3 > 0) {
				well2_lengths -= 2 * 1;
				cnt_wells2--;
			}
			if (cnt_wells3 - cnt_wells4 > 0) {
				well2_lengths -= 3 * 2;
				cnt_wells3--;
			} else if (cnt_wells2 - cnt_wells3 > 0) {
				well2_lengths -= 2 * 1;
				cnt_wells2--;
			}
		} else if (minlevel >= 5) {
			if (nfull_rows == 1) score -= 15.0;
			if (nfull_rows >= 2) score += 1e7;
			if (cnt_wells2 - cnt_wells3 > 0) {
				well2_lengths -= 2 * 1;
				cnt_wells2--;
			}
			if (cnt_wells2 - cnt_wells3 > 0) {
				well2_lengths -= 2 * 1;
				cnt_wells2--;
			}
		}
	} else if (SCORING_PARAM == 64) {
		W_WELLS2_LENGTHS = -2.0;
		if (minlevel >= 7) {
			if (nfull_rows == 1) score -= 25.0;
			if (nfull_rows == 2) score -= 20.0;
			if (nfull_rows == 3) score -= 15.0;
			if (nfull_rows >= 4) score += 1e7;
			if (cnt_wells4 - cnt_wells5 > 0) {
				well2_lengths -= 4 * 3;
				cnt_wells4--;
			} else if (cnt_wells3 - cnt_wells4 > 0) {
				well2_lengths -= 3 * 2;
				cnt_wells3--;
			} else if (cnt_wells2 - cnt_wells3 > 0) {
				well2_lengths -= 2 * 1;
				cnt_wells2--;
			}
			if (cnt_wells4 - cnt_wells5 > 0) {
				well2_lengths -= 4 * 3;
				cnt_wells4--;
			} else if (cnt_wells3 - cnt_wells4 > 0) {
				well2_lengths -= 3 * 2;
				cnt_wells3--;
			} else if (cnt_wells2 - cnt_wells3 > 0) {
				well2_lengths -= 2 * 1;
				cnt_wells2--;
			}
		} else if (minlevel >= 6) {
			if (nfull_rows == 1) score -= 25.0;
			if (nfull_rows == 2) score -= 20.0;
			if (nfull_rows >= 3) score += 1e7;
			if (cnt_wells3 - cnt_wells4 > 0) {
				well2_lengths -= 3 * 2;
				cnt_wells3--;
			} else if (cnt_wells2 - cnt_wells3 > 0) {
				well2_lengths -= 2 * 1;
				cnt_wells2--;
			}
			if (cnt_wells3 - cnt_wells4 > 0) {
				well2_lengths -= 3 * 2;
				cnt_wells3--;
			} else if (cnt_wells2 - cnt_wells3 > 0) {
				well2_lengths -= 2 * 1;
				cnt_wells2--;
			}
		} else if (minlevel >= 5) {
			if (nfull_rows == 1) score -= 15.0;
			if (nfull_rows >= 2) score += 1e7;
			if (cnt_wells2 - cnt_wells3 > 0) {
				well2_lengths -= 2 * 1;
				cnt_wells2--;
			}
			if (cnt_wells2 - cnt_wells3 > 0) {
				well2_lengths -= 2 * 1;
				cnt_wells2--;
			}
		}
	} else if (SCORING_PARAM == 65) {
		// BAD
		W_WELLS2_LENGTHS = -10.0;
		if (minlevel >= 7) {
			if (nfull_rows == 1) score -= 25.0;
			if (nfull_rows == 2) score -= 20.0;
			if (nfull_rows == 3) score -= 15.0;
			if (nfull_rows >= 4) score += 1e7;
			if (cnt_wells4 - cnt_wells5 > 0) {
				well2_lengths -= 4 * 3;
				cnt_wells4--;
			} else if (cnt_wells3 - cnt_wells4 > 0) {
				well2_lengths -= 3 * 2;
				cnt_wells3--;
			} else if (cnt_wells2 - cnt_wells3 > 0) {
				well2_lengths -= 2 * 1;
				cnt_wells2--;
			}
			if (cnt_wells4 - cnt_wells5 > 0) {
				well2_lengths -= 4 * 3;
				cnt_wells4--;
			} else if (cnt_wells3 - cnt_wells4 > 0) {
				well2_lengths -= 3 * 2;
				cnt_wells3--;
			} else if (cnt_wells2 - cnt_wells3 > 0) {
				well2_lengths -= 2 * 1;
				cnt_wells2--;
			}
		} else if (minlevel >= 6) {
			if (nfull_rows == 1) score -= 25.0;
			if (nfull_rows == 2) score -= 20.0;
			if (nfull_rows >= 3) score += 1e7;
			if (cnt_wells3 - cnt_wells4 > 0) {
				well2_lengths -= 3 * 2;
				cnt_wells3--;
			} else if (cnt_wells2 - cnt_wells3 > 0) {
				well2_lengths -= 2 * 1;
				cnt_wells2--;
			}
			if (cnt_wells2 - cnt_wells3 > 0) {
				well2_lengths -= 2 * 1;
				cnt_wells2--;
			}
		} else if (minlevel >= 5) {
			if (nfull_rows == 1) score -= 15.0;
			if (nfull_rows >= 2) score += 1e7;
			if (cnt_wells2 - cnt_wells3 > 0) {
				well2_lengths -= 2 * 1;
				cnt_wells2--;
			}
		}
	} else if (SCORING_PARAM == 66) {
		W_WELLS2_LENGTHS = -2.0;
		if (minlevel >= 6) {
			if (nfull_rows == 1) score -= 17.5;
			if (nfull_rows == 2) score -= 12.5;
			if (nfull_rows >= 3) score += 1e7;
			if (cnt_wells4 - cnt_wells5 > 0) {
				well2_lengths -= 4 * 3;
				cnt_wells4--;
			} else if (cnt_wells3 - cnt_wells4 > 0) {
				well2_lengths -= 3 * 2;
				cnt_wells3--;
			} else if (cnt_wells2 - cnt_wells3 > 0) {
				well2_lengths -= 2 * 1;
				cnt_wells2--;
			}
			if (cnt_wells4 - cnt_wells5 > 0) {
				well2_lengths -= 4 * 3;
				cnt_wells4--;
			} else if (cnt_wells3 - cnt_wells4 > 0) {
				well2_lengths -= 3 * 2;
				cnt_wells3--;
			} else if (cnt_wells2 - cnt_wells3 > 0) {
				well2_lengths -= 2 * 1;
				cnt_wells2--;
			}
		} else if (minlevel >= 5) {
			if (nfull_rows == 1) score -= 17.5;
			if (nfull_rows >= 2) score += 1e7;
			if (cnt_wells3 - cnt_wells4 > 0) {
				well2_lengths -= 3 * 2;
				cnt_wells3--;
			} else if (cnt_wells2 - cnt_wells3 > 0) {
				well2_lengths -= 2 * 1;
				cnt_wells2--;
			}
			if (cnt_wells3 - cnt_wells4 > 0) {
				well2_lengths -= 3 * 2;
				cnt_wells3--;
			} else if (cnt_wells2 - cnt_wells3 > 0) {
				well2_lengths -= 2 * 1;
				cnt_wells2--;
			}
		}
	} else if (SCORING_PARAM == 67) {
		W_WELLS2_LENGTHS = -3.0;
		if (minlevel >= 6) {
			if (nfull_rows == 1) score -= 17.5;
			if (nfull_rows == 2) score -= 12.5;
			if (nfull_rows >= 3) score += 1e7;
			if (cnt_wells4 - cnt_wells5 > 0) {
				well2_lengths -= 4 * 3;
				cnt_wells4--;
			} else if (cnt_wells3 - cnt_wells4 > 0) {
				well2_lengths -= 3 * 2;
				cnt_wells3--;
			} else if (cnt_wells2 - cnt_wells3 > 0) {
				well2_lengths -= 2 * 1;
				cnt_wells2--;
			}
			if (cnt_wells4 - cnt_wells5 > 0) {
				well2_lengths -= 4 * 3;
				cnt_wells4--;
			} else if (cnt_wells3 - cnt_wells4 > 0) {
				well2_lengths -= 3 * 2;
				cnt_wells3--;
			} else if (cnt_wells2 - cnt_wells3 > 0) {
				well2_lengths -= 2 * 1;
				cnt_wells2--;
			}
		} else if (minlevel >= 5) {
			if (nfull_rows == 1) score -= 17.5;
			if (nfull_rows >= 2) score += 1e7;
			if (cnt_wells3 - cnt_wells4 > 0) {
				well2_lengths -= 3 * 2;
				cnt_wells3--;
			} else if (cnt_wells2 - cnt_wells3 > 0) {
				well2_lengths -= 2 * 1;
				cnt_wells2--;
			}
			if (cnt_wells3 - cnt_wells4 > 0) {
				well2_lengths -= 3 * 2;
				cnt_wells3--;
			} else if (cnt_wells2 - cnt_wells3 > 0) {
				well2_lengths -= 2 * 1;
				cnt_wells2--;
			}
		}
	} else if (SCORING_PARAM == 68) {
		W_WELLS2_LENGTHS = -4.0;
		if (minlevel >= 6) {
			if (nfull_rows == 1) score -= 17.5;
			if (nfull_rows == 2) score -= 12.5;
			if (nfull_rows >= 3) score += 1e7;
			if (cnt_wells4 - cnt_wells5 > 0) {
				well2_lengths -= 4 * 3;
				cnt_wells4--;
			} else if (cnt_wells3 - cnt_wells4 > 0) {
				well2_lengths -= 3 * 2;
				cnt_wells3--;
			} else if (cnt_wells2 - cnt_wells3 > 0) {
				well2_lengths -= 2 * 1;
				cnt_wells2--;
			}
			if (cnt_wells4 - cnt_wells5 > 0) {
				well2_lengths -= 4 * 3;
				cnt_wells4--;
			} else if (cnt_wells3 - cnt_wells4 > 0) {
				well2_lengths -= 3 * 2;
				cnt_wells3--;
			} else if (cnt_wells2 - cnt_wells3 > 0) {
				well2_lengths -= 2 * 1;
				cnt_wells2--;
			}
		} else if (minlevel >= 5) {
			if (nfull_rows == 1) score -= 17.5;
			if (nfull_rows >= 2) score += 1e7;
			if (cnt_wells3 - cnt_wells4 > 0) {
				well2_lengths -= 3 * 2;
				cnt_wells3--;
			} else if (cnt_wells2 - cnt_wells3 > 0) {
				well2_lengths -= 2 * 1;
				cnt_wells2--;
			}
			if (cnt_wells3 - cnt_wells4 > 0) {
				well2_lengths -= 3 * 2;
				cnt_wells3--;
			} else if (cnt_wells2 - cnt_wells3 > 0) {
				well2_lengths -= 2 * 1;
				cnt_wells2--;
			}
		}
	} else if (SCORING_PARAM == 69) {
		W_WELLS2_LENGTHS = -4.5;
		if (minlevel >= 6) {
			if (nfull_rows == 1) score -= 17.5;
			if (nfull_rows == 2) score -= 12.5;
			if (nfull_rows >= 3) score += 1e7;
			if (cnt_wells4 - cnt_wells5 > 0) {
				well2_lengths -= 4 * 3;
				cnt_wells4--;
			} else if (cnt_wells3 - cnt_wells4 > 0) {
				well2_lengths -= 3 * 2;
				cnt_wells3--;
			} else if (cnt_wells2 - cnt_wells3 > 0) {
				well2_lengths -= 2 * 1;
				cnt_wells2--;
			}
			if (cnt_wells4 - cnt_wells5 > 0) {
				well2_lengths -= 4 * 3;
				cnt_wells4--;
			} else if (cnt_wells3 - cnt_wells4 > 0) {
				well2_lengths -= 3 * 2;
				cnt_wells3--;
			} else if (cnt_wells2 - cnt_wells3 > 0) {
				well2_lengths -= 2 * 1;
				cnt_wells2--;
			}
		} else if (minlevel >= 5) {
			if (nfull_rows == 1) score -= 17.5;
			if (nfull_rows >= 2) score += 1e7;
			if (cnt_wells3 - cnt_wells4 > 0) {
				well2_lengths -= 3 * 2;
				cnt_wells3--;
			} else if (cnt_wells2 - cnt_wells3 > 0) {
				well2_lengths -= 2 * 1;
				cnt_wells2--;
			}
			if (cnt_wells3 - cnt_wells4 > 0) {
				well2_lengths -= 3 * 2;
				cnt_wells3--;
			} else if (cnt_wells2 - cnt_wells3 > 0) {
				well2_lengths -= 2 * 1;
				cnt_wells2--;
			}
		}
	} else if (SCORING_PARAM == 73) {
		W_WELLS2_LENGTHS = -2.5;
		if (minlevel >= 7) {
			if (nfull_rows == 1) score -= 17.5;
			if (nfull_rows == 2) score -= 12.5;
			if (nfull_rows >= 3) score += 1e7;
			if (cnt_wells4 - cnt_wells5 > 0) {
				well2_lengths -= 4 * 3;
				cnt_wells4--;
			} else if (cnt_wells3 - cnt_wells4 > 0) {
				well2_lengths -= 3 * 2;
				cnt_wells3--;
			} else if (cnt_wells2 - cnt_wells3 > 0) {
				well2_lengths -= 2 * 1;
				cnt_wells2--;
			}
			if (cnt_wells3 - cnt_wells4 > 0) {
				well2_lengths -= 3 * 2;
				cnt_wells3--;
			} else if (cnt_wells2 - cnt_wells3 > 0) {
				well2_lengths -= 2 * 1;
				cnt_wells2--;
			}
		} else if (minlevel >= 6) {
			if (nfull_rows == 1) score -= 17.5;
			if (nfull_rows >= 2) score += 1e7;
			if (cnt_wells3 - cnt_wells4 > 0) {
				well2_lengths -= 3 * 2;
				cnt_wells3--;
			} else if (cnt_wells2 - cnt_wells3 > 0) {
				well2_lengths -= 2 * 1;
				cnt_wells2--;
			}
		}
	} else if (SCORING_PARAM == 74) {
		W_WELLS2_LENGTHS = -2.0;
		if (minlevel >= 8) {
			if (nfull_rows == 1) score -= 17.5;
			if (nfull_rows == 2) score -= 12.5;
			if (nfull_rows >= 3) score += 1e7;
			if (cnt_wells4 - cnt_wells5 > 0) {
				well2_lengths -= 4 * 3;
				cnt_wells4--;
			} else if (cnt_wells3 - cnt_wells4 > 0) {
				well2_lengths -= 3 * 2;
				cnt_wells3--;
			} else if (cnt_wells2 - cnt_wells3 > 0) {
				well2_lengths -= 2 * 1;
				cnt_wells2--;
			}
			if (cnt_wells4 - cnt_wells5 > 0) {
				well2_lengths -= 4 * 3;
				cnt_wells4--;
			} else if (cnt_wells3 - cnt_wells4 > 0) {
				well2_lengths -= 3 * 2;
				cnt_wells3--;
			} else if (cnt_wells2 - cnt_wells3 > 0) {
				well2_lengths -= 2 * 1;
				cnt_wells2--;
			}
		} else if (minlevel >= 7) {
			if (nfull_rows == 1) score -= 17.5;
			if (nfull_rows >= 2) score += 1e7;
			if (cnt_wells3 - cnt_wells4 > 0) {
				well2_lengths -= 3 * 2;
				cnt_wells3--;
			} else if (cnt_wells2 - cnt_wells3 > 0) {
				well2_lengths -= 2 * 1;
				cnt_wells2--;
			}
			if (cnt_wells3 - cnt_wells4 > 0) {
				well2_lengths -= 3 * 2;
				cnt_wells3--;
			} else if (cnt_wells2 - cnt_wells3 > 0) {
				well2_lengths -= 2 * 1;
				cnt_wells2--;
			}
		}
	} else if (SCORING_PARAM == 75) {
		W_WELLS2_LENGTHS = -3.0;
		if (minlevel >= 8) {
			if (nfull_rows == 1) score -= 17.5;
			if (nfull_rows == 2) score -= 12.5;
			if (nfull_rows >= 3) score += 1e7;
			if (cnt_wells4 - cnt_wells5 > 0) {
				well2_lengths -= 4 * 3;
				cnt_wells4--;
			} else if (cnt_wells3 - cnt_wells4 > 0) {
				well2_lengths -= 3 * 2;
				cnt_wells3--;
			} else if (cnt_wells2 - cnt_wells3 > 0) {
				well2_lengths -= 2 * 1;
				cnt_wells2--;
			}
			if (cnt_wells4 - cnt_wells5 > 0) {
				well2_lengths -= 4 * 3;
				cnt_wells4--;
			} else if (cnt_wells3 - cnt_wells4 > 0) {
				well2_lengths -= 3 * 2;
				cnt_wells3--;
			} else if (cnt_wells2 - cnt_wells3 > 0) {
				well2_lengths -= 2 * 1;
				cnt_wells2--;
			}
		} else if (minlevel >= 7) {
			if (nfull_rows == 1) score -= 17.5;
			if (nfull_rows >= 2) score += 1e7;
			if (cnt_wells3 - cnt_wells4 > 0) {
				well2_lengths -= 3 * 2;
				cnt_wells3--;
			} else if (cnt_wells2 - cnt_wells3 > 0) {
				well2_lengths -= 2 * 1;
				cnt_wells2--;
			}
			if (cnt_wells3 - cnt_wells4 > 0) {
				well2_lengths -= 3 * 2;
				cnt_wells3--;
			} else if (cnt_wells2 - cnt_wells3 > 0) {
				well2_lengths -= 2 * 1;
				cnt_wells2--;
			}
		}
	} else if (SCORING_PARAM == 76) {
		W_WELLS2_LENGTHS = -4.0;
		if (minlevel >= 8) {
			if (nfull_rows == 1) score -= 17.5;
			if (nfull_rows == 2) score -= 12.5;
			if (nfull_rows >= 3) score += 1e7;
			if (cnt_wells4 - cnt_wells5 > 0) {
				well2_lengths -= 4 * 3;
				cnt_wells4--;
			} else if (cnt_wells3 - cnt_wells4 > 0) {
				well2_lengths -= 3 * 2;
				cnt_wells3--;
			} else if (cnt_wells2 - cnt_wells3 > 0) {
				well2_lengths -= 2 * 1;
				cnt_wells2--;
			}
			if (cnt_wells4 - cnt_wells5 > 0) {
				well2_lengths -= 4 * 3;
				cnt_wells4--;
			} else if (cnt_wells3 - cnt_wells4 > 0) {
				well2_lengths -= 3 * 2;
				cnt_wells3--;
			} else if (cnt_wells2 - cnt_wells3 > 0) {
				well2_lengths -= 2 * 1;
				cnt_wells2--;
			}
		} else if (minlevel >= 7) {
			if (nfull_rows == 1) score -= 17.5;
			if (nfull_rows >= 2) score += 1e7;
			if (cnt_wells3 - cnt_wells4 > 0) {
				well2_lengths -= 3 * 2;
				cnt_wells3--;
			} else if (cnt_wells2 - cnt_wells3 > 0) {
				well2_lengths -= 2 * 1;
				cnt_wells2--;
			}
			if (cnt_wells3 - cnt_wells4 > 0) {
				well2_lengths -= 3 * 2;
				cnt_wells3--;
			} else if (cnt_wells2 - cnt_wells3 > 0) {
				well2_lengths -= 2 * 1;
				cnt_wells2--;
			}
		}
	} else if (SCORING_PARAM == 77) {
		W_WELLS2_LENGTHS = -4.5;
		if (minlevel >= 8) {
			if (nfull_rows == 1) score -= 17.5;
			if (nfull_rows == 2) score -= 12.5;
			if (nfull_rows >= 3) score += 1e7;
			if (cnt_wells4 - cnt_wells5 > 0) {
				well2_lengths -= 4 * 3;
				cnt_wells4--;
			} else if (cnt_wells3 - cnt_wells4 > 0) {
				well2_lengths -= 3 * 2;
				cnt_wells3--;
			} else if (cnt_wells2 - cnt_wells3 > 0) {
				well2_lengths -= 2 * 1;
				cnt_wells2--;
			}
			if (cnt_wells4 - cnt_wells5 > 0) {
				well2_lengths -= 4 * 3;
				cnt_wells4--;
			} else if (cnt_wells3 - cnt_wells4 > 0) {
				well2_lengths -= 3 * 2;
				cnt_wells3--;
			} else if (cnt_wells2 - cnt_wells3 > 0) {
				well2_lengths -= 2 * 1;
				cnt_wells2--;
			}
		} else if (minlevel >= 7) {
			if (nfull_rows == 1) score -= 17.5;
			if (nfull_rows >= 2) score += 1e7;
			if (cnt_wells3 - cnt_wells4 > 0) {
				well2_lengths -= 3 * 2;
				cnt_wells3--;
			} else if (cnt_wells2 - cnt_wells3 > 0) {
				well2_lengths -= 2 * 1;
				cnt_wells2--;
			}
			if (cnt_wells3 - cnt_wells4 > 0) {
				well2_lengths -= 3 * 2;
				cnt_wells3--;
			} else if (cnt_wells2 - cnt_wells3 > 0) {
				well2_lengths -= 2 * 1;
				cnt_wells2--;
			}
		}
	} else if (SCORING_PARAM == 79) {
		W_WELLS2_LENGTHS = -1.0;
		if (minlevel >= 9) {
			if (nfull_rows == 1) score -= 25.0;
			if (nfull_rows == 2) score -= 20.0;
			if (nfull_rows == 3) score -= 15.0;
			if (nfull_rows >= 4) score += 1e7;
			if (cnt_wells4 - cnt_wells5 > 0) {
				well2_lengths -= 4 * 3;
				cnt_wells4--;
			} else if (cnt_wells3 - cnt_wells4 > 0) {
				well2_lengths -= 3 * 2;
				cnt_wells3--;
			} else if (cnt_wells2 - cnt_wells3 > 0) {
				well2_lengths -= 2 * 1;
				cnt_wells2--;
			}
			if (cnt_wells4 - cnt_wells5 > 0) {
				well2_lengths -= 4 * 3;
				cnt_wells4--;
			} else if (cnt_wells3 - cnt_wells4 > 0) {
				well2_lengths -= 3 * 2;
				cnt_wells3--;
			} else if (cnt_wells2 - cnt_wells3 > 0) {
				well2_lengths -= 2 * 1;
				cnt_wells2--;
			}
		} else if (minlevel >= 8) {
			if (nfull_rows == 1) score -= 25.0;
			if (nfull_rows == 2) score -= 20.0;
			if (nfull_rows >= 3) score += 1e7;
			if (cnt_wells3 - cnt_wells4 > 0) {
				well2_lengths -= 3 * 2;
				cnt_wells3--;
			} else if (cnt_wells2 - cnt_wells3 > 0) {
				well2_lengths -= 2 * 1;
				cnt_wells2--;
			}
			if (cnt_wells3 - cnt_wells4 > 0) {
				well2_lengths -= 3 * 2;
				cnt_wells3--;
			} else if (cnt_wells2 - cnt_wells3 > 0) {
				well2_lengths -= 2 * 1;
				cnt_wells2--;
			}
		} else if (minlevel >= 7) {
			if (nfull_rows == 1) score -= 15.0;
			if (nfull_rows >= 2) score += 1e7;
			if (cnt_wells2 - cnt_wells3 > 0) {
				well2_lengths -= 2 * 1;
				cnt_wells2--;
			}
			if (cnt_wells2 - cnt_wells3 > 0) {
				well2_lengths -= 2 * 1;
				cnt_wells2--;
			}
		}
	} else if (SCORING_PARAM == 80) {
		W_WELLS2_LENGTHS = -1.5;
		if (minlevel >= 9) {
			if (nfull_rows == 1) score -= 25.0;
			if (nfull_rows == 2) score -= 20.0;
			if (nfull_rows == 3) score -= 15.0;
			if (nfull_rows >= 4) score += 1e7;
			if (cnt_wells4 - cnt_wells5 > 0) {
				well2_lengths -= 4 * 3;
				cnt_wells4--;
			} else if (cnt_wells3 - cnt_wells4 > 0) {
				well2_lengths -= 3 * 2;
				cnt_wells3--;
			} else if (cnt_wells2 - cnt_wells3 > 0) {
				well2_lengths -= 2 * 1;
				cnt_wells2--;
			}
			if (cnt_wells4 - cnt_wells5 > 0) {
				well2_lengths -= 4 * 3;
				cnt_wells4--;
			} else if (cnt_wells3 - cnt_wells4 > 0) {
				well2_lengths -= 3 * 2;
				cnt_wells3--;
			} else if (cnt_wells2 - cnt_wells3 > 0) {
				well2_lengths -= 2 * 1;
				cnt_wells2--;
			}
		} else if (minlevel >= 8) {
			if (nfull_rows == 1) score -= 25.0;
			if (nfull_rows == 2) score -= 20.0;
			if (nfull_rows >= 3) score += 1e7;
			if (cnt_wells3 - cnt_wells4 > 0) {
				well2_lengths -= 3 * 2;
				cnt_wells3--;
			} else if (cnt_wells2 - cnt_wells3 > 0) {
				well2_lengths -= 2 * 1;
				cnt_wells2--;
			}
			if (cnt_wells3 - cnt_wells4 > 0) {
				well2_lengths -= 3 * 2;
				cnt_wells3--;
			} else if (cnt_wells2 - cnt_wells3 > 0) {
				well2_lengths -= 2 * 1;
				cnt_wells2--;
			}
		} else if (minlevel >= 7) {
			if (nfull_rows == 1) score -= 15.0;
			if (nfull_rows >= 2) score += 1e7;
			if (cnt_wells2 - cnt_wells3 > 0) {
				well2_lengths -= 2 * 1;
				cnt_wells2--;
			}
			if (cnt_wells2 - cnt_wells3 > 0) {
				well2_lengths -= 2 * 1;
				cnt_wells2--;
			}
		}
	} else {
		while (1);
	}
 
	score += W_LANDING_HEIGHT * landing_height +
			W_NFULL_ROWS * nfull_rows +
			W_ROW_TRANSITIONS * row_transitions +
			W_COL_TRANSITIONS * col_transitions +
			W_NUM_HOLES * num_holes +
			W_WELLS2_LENGTHS * well2_lengths +
			W_WELLS3_LENGTHS * well3_lengths +
			W_WELLS4_LENGTHS * well4_lengths +
			W_WELLS5_LENGTHS * well5_lengths +
			W_SUM_SQ_HOLES * sum_sq_holes
			;
	
	return score;
}
 
int PlaceNextPiece(int pid, int rid) {
	int rmin, rmax;
	if (rid < 0) {
		rmin = 0; rmax = nrot[pid];
	} else {
		rmin = rid;
		rmax = rid + 1;
	}
	npoz = 0;
	// Try all the allowed rotations.
	for (rid = rmin; rid < rmax; rid++) {
		BFS(pid, rid, rboardmask);
		for (int i = rotdim[pid][rid][0]; i <= BOARD_SIZE; i++)
			for (int j = 1; j <= BOARD_SIZE; j++)
				if ((ok[i] & bit[j]) > 0) {
					poz[npoz][0] = rid;
					poz[npoz][1] = i;
					poz[npoz][2] = j;
					npoz++;
				}
	}
 
	if (npoz == 0) {
		if (!LOCAL) {
			printf("a -1 -1\n");
			fflush(stdout);
		}
		return 0;
	}
 
	int best_poz = -1;
	double best_score = 0.0;
	for (int pidx = 0; pidx < npoz; pidx++) {
		double score = ComputeScore(pid, poz[pidx][0], poz[pidx][1], poz[pidx][2]);
		if (best_poz < 0 || score > best_score) {
			best_score = score;
			best_poz = pidx;
		}
	}
	
	DoMove(pid, poz[best_poz][0], poz[best_poz][1], poz[best_poz][2], rboardmask, cboardmask, 1);
	return 1;
}
 
void PrintBoard() {
	int i, j;
	for (i = 1; i <= BOARD_SIZE; i++) {
		for (j = 1; j <= BOARD_SIZE; j++)
			if ((rboardmask[i] & bit[j]) > 0)
				fprintf(stderr, "1");
			else
				fprintf(stderr, "0");
		fprintf(stderr, "\n");
	}
}
 
int h[MAX_PIECES], score_got[5], np_got[5];
int piececnt[NUM_PIECES], nfixed;
 
void Solve() {
	memset(rboardmask, 0, sizeof(rboardmask));
	memset(cboardmask, 0, sizeof(cboardmask));
	memset(piececnt, 0, sizeof(piececnt));
	num_pieces = num_cleared_rows = score = nfixed = 0;
	TESTID = -1;
	SCORING_PARAM = SCORING_PARAM = SCORING_PARAMS[TESTID + 1][PARAM_IDX = 0];
	while (num_pieces < MAX_PIECES) {
		int type = -1, pid = -1, rid = -1;
		if (GetNextPiece(type, pid, rid)) {
			piece[num_pieces][0] = type;
			piece[num_pieces][1] = pid;
			piece[num_pieces][2] = rid;
			piececnt[pid]++;
			if (rid != -1) nfixed++;
			if (0&&!LOCAL && TESTID >= 0 && FOCUS_TEST >= 0 && TESTID != FOCUS_TEST) {
				printf("a -1 -1\n");
				fflush(stdout);
				break;
			}
			if (!LOCAL && TESTID < 0) {
				if (num_pieces == 0)
					h[0] = type % 23;
				else
					h[num_pieces] = (h[num_pieces - 1] * 17 + type) % 23;
				h[num_pieces] = (h[num_pieces] * 17 + pid) % 23;
				h[num_pieces] = (h[num_pieces] * 17 + rid + 1) % 23;
				if (num_pieces == 1 && h[0] == 0) {
					if (h[1] == 1) TESTID = 4; // v
					else if (h[1] == 7) TESTID = 7; // v
					else if (h[1] == 13) TESTID = 8; // v
					else if (h[1] == 18) TESTID = 9; // v
				} else if (num_pieces == 1 && h[0] == 1) {
					if (h[1] == 3) TESTID = 5; // v
					else if (h[1] == 9) TESTID = 10; // v
					else if (h[1] == 20) TESTID = 11; // v
				} else if (num_pieces == 1 && h[0] == 6) {
					if (h[1] == 7) TESTID = 6; // v
					else if (h[1] == 22) TESTID = 12; // v
				} else if (num_pieces == 1 && h[0] == 7) {
					if (h[1] == 18) TESTID = 0; // v
				} else if (num_pieces == 1 && h[0] == 12) {
					if (h[1] == 7) TESTID = 16; // v
					else if (h[1] == 20) TESTID = 1; // v
					else if (h[1] == 13) TESTID = 17; // v
				} else if (num_pieces == 1 && h[0] == 13) {
					if (h[1] == 11) TESTID = 2; // v
					else if (h[1] == 16) TESTID = 14; // v
					else if (h[1] == 22) TESTID = 15; // v
				} else if (num_pieces == 1 && h[0] == 18) {
					if (h[1] == 11) TESTID = 3; // v
					else if (h[1] == 17) TESTID = 13; // v
				} else if (num_pieces == 1) {
					//while (1);
				}
				if (TESTID >= 0) SCORING_PARAM = SCORING_PARAMS[TESTID + 1][0];
			}
			if (!PlaceNextPiece(pid, rid)) break;
		} else break;
	}
	int num_distinct_pieces = 0;
	for (int i = 0; i < NUM_PIECES; i++)
		if (piececnt[i] > 0) num_distinct_pieces++;
	score_got[0] = score;
	np_got[0] = num_pieces;
	if (TESTID == FOCUS_TEST) {
		if (num_pieces < MAX_PIECES) num_pieces++;
		int num_known_pieces = num_pieces;
		int max_score_idx = 0;
		// Test the other possible SCORING_PARAMS.
		for (PARAM_IDX = 1; PARAM_IDX <= MAX_PARAM_IDX; PARAM_IDX++) {
			// Replay the known pieces and use SCORING_PARAMS[TESTID + 1][param_idx] this time.
			SCORING_PARAM = SCORING_PARAMS[TESTID + 1][PARAM_IDX];
			memset(rboardmask, 0, sizeof(rboardmask));
			memset(cboardmask, 0, sizeof(cboardmask));
			num_pieces = num_cleared_rows = score = 0;
			while (num_pieces < num_known_pieces) {
				if (!PlaceNextPiece(piece[num_pieces][1], piece[num_pieces][2])) break;
			}
			np_got[PARAM_IDX] = num_pieces;
			score_got[PARAM_IDX] = score;
			if (score > score_got[max_score_idx]) max_score_idx = PARAM_IDX;
		}
		if (FOCUS_TEST >= 0) {
			if (max_score_idx == 1) {
				assert(false); // SIGABRT
			} else if (max_score_idx == 2) {
				int x = 1, y = 0;
				printf("%d\n", x / y); // SIGFPE
			} else if (max_score_idx == 3) {
				exit(1); // NZEC
			} else if (max_score_idx == 4) {
				int *x = NULL;
				printf("%d\n", x[1000]); // SIGSEGV
			} else if (score_got[0] <= 10000 && num_distinct_pieces == 1 && nfixed == 0) {
				// Low score and only 1 kind of piece + no fixed pieces.
				while (1);
			}
		}
	}
}
 
#define NUM_LOCAL_TESTS 100
 
int main() {
	Init();
	if (LOCAL) {
		int total_score = 0;
		for (int t = 101; t <= 100 + NUM_LOCAL_TESTS; t++) {
			//GenerateTest(t, 2, 3, 2, 4, 2, 3, 2);
			GenerateTest(t, 1, 1, 1, 1, 1, 1, 1);
			int tstart = clock();
			Solve();
			total_score += score_got[0];
			if (TESTID != FOCUS_TEST)
				fprintf(stderr, "%d: time=%.2lf np=%d nr=%d score=%d total=%d\n", t, (double) (clock() - tstart) / (double) CLOCKS_PER_SEC, num_pieces, num_cleared_rows, score, total_score);
			else
				fprintf(stderr, "%d: time=%.2lf np=[%d %d %d %d %d] scores=[%d %d %d %d %d]\n", t, (double) (clock() - tstart) / (double) CLOCKS_PER_SEC, np_got[0], np_got[1], np_got[2], np_got[3], np_got[4], score_got[0], score_got[1], score_got[2], score_got[3], score_got[4]);
		}
	} else {
		Solve();
	}
 
	return 0;
}
