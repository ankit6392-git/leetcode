class Solution {
    private boolean canTripBeCompleted(long timeAllowed, int[]time,int totalTrips){
        long trips=0;
        for(int tripTime:time){
            trips+=(timeAllowed/tripTime);
        }
        return trips>= totalTrips;
    }
    public long minimumTime(int[] time, int totalTrips) {
        long low=Integer.MAX_VALUE;
…                low=mid+1;
            }
         }
         return low;
    }
}
