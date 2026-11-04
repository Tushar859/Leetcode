class Solution {
public:
    bool valid (int t ,vector<int>& piles, int h){
         int n = piles.size();
         double hr =0;
      for(int i=0;i<n;i++){
         hr += ceil((double)piles[i] / t);
      }
      return hr <= h;   
    }
    int minEatingSpeed(vector<int>& piles, int h) {
    
     int ans  = 0;
     int maxi = *max_element(piles.begin(),piles.end());
     // tle now we need use binary search on answer/
      int low=0,high=maxi;
      while(low<=high){
        int mid = (low+high)/2;
        if(valid(mid,piles,h)){
            ans = mid;
            // now we can move left for less
            high = mid-1;
        }
        else{
            // not valid wee should move right for our search
            low  = mid+1;

        }
      }
    //  for(int k=1;k<=maxi;k++){
    //    if(valid(k,piles,h)){
    //      ans = k;
    //      break;
    //    }
    //  }
     return low;
    }
};