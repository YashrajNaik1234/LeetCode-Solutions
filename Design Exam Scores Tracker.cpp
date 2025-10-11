class ExamTracker {
public:
    vector<int> times;
    vector<long long> scoreSum;
    ExamTracker() {
        
    }
    
    void record(int time, int score) {
        times.push_back(time);
        scoreSum.push_back((scoreSum.empty() ? 0 : scoreSum.back()) + score);
        
    }
    
    long long totalScore(int startTime, int endTime) {
        int left = lower_bound(times.begin(), times.end(), startTime) - times.begin();
        int right = upper_bound(times.begin(), times.end(), endTime) - 1 - times.begin();

        if(left > right) return 0;
        return (scoreSum[right] - (left > 0 ? scoreSum[left - 1] : 0));
    }

};
