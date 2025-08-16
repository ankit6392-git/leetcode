class Solution {
public:
   int maximumPopulation(vector<vector<int>>& logs) {
    vector<int> ans(101, 0);   
    for (int i = 0; i < logs.size(); i++) {
        int birth = logs[i][0];
        int death = logs[i][1];
        ans[birth - 1950] += 1;
        ans[death - 1950] -= 1; 
    }
    int maxpopulation = 0;
    int maxyear = 1950;
    int currentpopulation = 0;
    for(int i = 0; i <= 100; i++){
        currentpopulation += ans[i];
        int year = 1950 + i;
        if(currentpopulation > maxpopulation){
            maxpopulation = currentpopulation;
            maxyear = year;
        }
    }
    return maxyear;
}
};
