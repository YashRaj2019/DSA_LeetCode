class Solution {
public:
    int toSecond(string startTime) {
        int h1 = stoi(startTime.substr(0,2));
        int m1 = stoi(startTime.substr(3,2));
        int s1 = stoi(startTime.substr(6,2));

         int start = h1*3600+m1*60+s1;
         return start;
    }
    int secondsBetweenTimes(string startTime, string endTime) {

        return toSecond(endTime) - toSecond(startTime);
    }
};