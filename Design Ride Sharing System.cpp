class RideSharingSystem {
public:
    queue<int> driver;
    queue<int> rider,cancelrider;
    RideSharingSystem() {
        
    }
    
    void addRider(int riderId) {
        rider.push(riderId);
    }
    
    void addDriver(int driverId) {
        driver.push(driverId);
    }
    
    vector<int> matchDriverWithRider() {
        vector<int> x = {-1, -1};
        if(!rider.empty() and !driver.empty()){
            x.front() = driver.front(); driver.pop();
            x.back() = rider.front(); rider.pop();
        }

        return x;
    }
    
    void cancelRider(int riderId) {
        while(!rider.empty()){
            if(rider.front() == riderId){
                rider.pop(); continue;
            }
            cancelrider.push(rider.front()); rider.pop();
        }

        while(!cancelrider.empty()){
            rider.push(cancelrider.front()); cancelrider.pop();
        }
    }
};
©leetcode
