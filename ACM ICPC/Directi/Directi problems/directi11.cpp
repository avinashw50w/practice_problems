/*Suppose you have some guests arriving at a party. For each guest, you are given the arrival and departure time.
When a guest arrives he is given a wine glass and when he leaves he returns that wine glass (it becomes available 
to be given to another guest). Find the minimum number of wine glasses needed to serve all the guests. The arrival 
and departure team can only be between 1800 to 2359 hours.*/

int minGlasses(int *arrival_time, int *departure_time, int N) 
{
	int arrival[N] = {}, departure[N] = {};

	REP(i, 0, N)
	{
		arrival[arrival_time[i] - 1800]++;
		deaprture[departure_time[i] - 1800]++;
	}

	int res = 0, available_glasses = 0;

	REP(i, 0, 560)
	{	
		// the no of persons leaving at time i(ie, departure[i]) 
		// will leave behind departure[i] no of glasses
		available_glasses += departure[i];

		// if ther are more persons than the available glasses
		if(arrival[i] > available_glasses)
		{
			// arrange extra glasses for them
			res += arrival[i] - available_glasses;
			// after giving glasses to everyone, there are no glasses left
			available_glasses = 0;
		}
		// if there are extra glasses, remove them
		else
		{
			available_glasses -= arrival[i];
		}
	}

	return res;

}