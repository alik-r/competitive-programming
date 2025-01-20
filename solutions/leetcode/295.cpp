class MedianFinder {
private:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap; 
    int count;
public:
    MedianFinder() {
        count = 0;
    }
    
    void addNum(int num) {
        if (maxHeap.empty()) {
            maxHeap.push(num);
            return;
        }

        if (num <= maxHeap.top()) maxHeap.push(num);
        else minHeap.push(num);

        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }

        if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if (maxHeap.size() > minHeap.size()) return maxHeap.top();
        return (maxHeap.top() + minHeap.top()) / (double)2.0;
    }
};
