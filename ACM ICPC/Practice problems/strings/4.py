s = raw_input()
n = len(s)
q = int(raw_input())
for i in xrange(q):
	l1,r1,l2,r2 = map(int, raw_input().split(" "))
	a = s[l1-1:r1]
	b = s[l2-1:r2]
	if(a == b):
		print "Yes"
	else:
		print "No"