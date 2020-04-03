// linear diophantine equation 

int main() {
	ll n, a,b,c,d;
	caset{
		cin>>a>>b>>c>>d;
		ll p = abs(b-a); 
		ll g = __gcd(c,d); 
		if(p%g == 0){
			printf("0\n");
			continue;
		}
		else{
			ll ans = 0;
			ans = min(p%g, g-(p%g));
			printf("%lld\n", ans);
			continue;
		}
	}
	return 0;
}
