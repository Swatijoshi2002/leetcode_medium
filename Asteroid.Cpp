vector<int> asteroidCollision(vector<int>& list) {
        
        int elem;
        bool flag = true;
        stack<int> stak;
        for( int i = 0 ; i < list.size() ; i++ ){
            if( stak.empty() ){
                stak.push( list[i] );
                continue;
            }
            
            elem = list[i];
            cout<<i<<" ";
            while( !stak.empty() &&  elem < 0 && stak.top() > 0  ){
                int a = stak.top(); stak.pop();
                if( abs(a) > abs(elem) ){
                    elem = a ;
                }
                else if( abs(elem) > abs(a) ){
                    //
                }
                else{
                    elem = 0 ;
                    flag = false;
                }
            }
            if( flag ){
                stak.push( elem );
                
            }
            flag = true;
        }
        
        vector<int> arr(stak.size());
        int i = stak.size()-1;
        while( i >= 0 ){
            arr[i] = stak.top(); 
            stak.pop();
            i--;
        }
        
        return arr;
    }
};
