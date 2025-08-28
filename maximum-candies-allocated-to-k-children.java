class Solution {
    private boolean canCandiesBeDistributed(long candiesToBeGiven,int[]candies,long k){
        long children=0;
        for(int candy:candies){
            children+=(candy/candiesToBeGiven);
        }
        return children>=k;
    }
    public int maximumCandies(int[] candies, long k) {
        long low=1;
…            }
        }
        return (int)high;
    }
}
