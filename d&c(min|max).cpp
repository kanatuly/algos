ll a[N], mx[N], mn[N];

void go(int l, int r){
    if (l + 1 == r){
        return;
    }
    int m = (l+r) >> 1;
    go(l, m);
    go(m, r);

    mn[m-1] = mx[m-1] = a[m-1];
    for (int i = m-2; i >= l; i--){
        mn[i] = min(mn[i+1], a[i]);
        mx[i] = max(mx[i+1], a[i]);
    }
    mn[m] = mx[m] = a[m];
    for (int i = m+1; i < r; i++){
        mn[i] = min(mn[i-1], a[i]);
        mx[i] = max(mx[i-1], a[i]);
    }
    //, mnmx
    for (int i = m, L = m-1; i < r; i++){
        while (L >= l && mn[i] <= mn[L] && mx[L] <= mx[i]){
            L--;
        }
        //(L, m)
        
    }

    //mnmx, 
    for (int i = m-1, L = m; i >= l; i--){
        while (L < r && mn[i] <= mn[L] && mx[L] < mx[i]){
            L++;
        }
        //[m, L)
        
    }
    //mn,mx
    for (int i = m, L = m-1, R = m-1; i < r; i++){
        while (L >= l && mx[i] >= mx[L]){
            add(L);
            L--;
        }
        while (R >= l && mn[i] <= mn[R]){
            del(R);
            R--;
        }
        // (L, R]
    }
    
    // mx, mn
    for (int i = m-1, L = m, R = m; i >= l; i--){
        while (L < r && mx[i] > mx[L]){
            add(L);
            L++;
        }
        while (R < r && mn[i] <= mn[R]){
            del(R);
            R++;
        }
        // [R, L)
    }
}
