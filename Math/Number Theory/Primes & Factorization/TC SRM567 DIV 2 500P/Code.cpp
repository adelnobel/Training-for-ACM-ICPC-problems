class TheSquareRootDilemma {
public:
	int get_twin(int n){
		
		int ret = 1;
		
		int to = sqrt(n) + 1;
		
		for(int i = 2; i <= to; i++){
			
			int tot = 0;
			while(n % i == 0){
				n /= i;
				to = sqrt(n) + 1;
				tot++;
			}
			
			if(tot % 2 == 1)
                             ret *= i;
		}
		
		if(n != 1)
                    ret *= n;
			
		return ret;
	}

	int countPairs(int N, int M) {
	
		int ret = 0;
	
		for(int i = 1; i <= M; i++){
			
			int twin = get_twin(i);
			
			for(int j = 1; j * j <= N; j++){
				
				if(twin * j*j > N ) break;
				
				ret++;
			
			}
		}
		
		return ret;
	}
};