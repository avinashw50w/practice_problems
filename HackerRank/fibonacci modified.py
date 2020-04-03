def f(n,t1,t2):
    fib = []
    fib.append(t1)
    fib.append(t2)
    x=3
    while x<=n:
        p = fib[-2] + fib[-1]**2
        fib.append(p)
        x+=1
    print(fib[n-1])

if __name__=="__main__":
    t1, t2, n = map(int, input().split())
    f(n,t1,t2)