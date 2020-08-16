int st[N][K + 1];

void build(){
	for (int i = 0; i < N; i++)
	    st[i][0] = array[i];

	for (int j = 1; j <= K; j++)
	    for (int i = 0; i + (1 << j) <= N; i++)
	        st[i][j] = st[i][j-1] + st[i + (1 << (j - 1))][j - 1];
}

int query(int L, int R){
	long long sum = 0;
	for (int j = K; j >= 0; j--) {
	    if ((1 << j) <= R - L + 1) {
	        sum += st[L][j];
	        L += 1 << j;
	    }
	}
	return sum;
}

// If the function is idempotent then use the BELOW code as it provides O(1) query.
// Idempotent functions means f(f(a)) = f(a). Example Minimum, GCD, etc.

int st[N][K + 1], logtwo[N];

void build(){
	logtwo[1] = 0;
	for (int i = 2; i <= MAXN; i++)
	    logtwo[i] = logtwo[i/2] + 1;
	for (int i = 0; i < N; i++)
	    st[i][0] = array[i];

	for (int j = 1; j <= K; j++)
	    for (int i = 0; i + (1 << j) <= N; i++)
	        st[i][j] = min(st[i][j-1], st[i + (1 << (j - 1))][j - 1]);
}

int query(int L, int R){
	int j = log[R - L + 1];
	int minimum = min(st[L][j], st[R - (1 << j) + 1][j]);
	return minimum;
}