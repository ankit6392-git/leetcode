class Solution {
    public int furthestBuilding(int[] heights, int bricks, int ladders) {
        PriorityQueue<Integer>minHeap=new PriorityQueue<>((a,b)->a-b);

        for(int i=0;i<heights.length-1;i++){
            int diff=heights[i+1]-heights[i];
            if(diff>0){
                minHeap.add(diff);
                if(minHeap.size()>ladders){
                    if(bricks<minHeap.peek()) {
                        return i;
                    }
                    bricks-=minHeap.poll();
                }
            }
        }
        return heights.length-1;
    }
}
