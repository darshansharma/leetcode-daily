// question link - https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix

struct myMinHeap{
    public: 
    vector<int> heap;
    
    void heapifyUp(int i){
        if (i == 0) return;
        int parentIndex = (i-1)/2;
        if (heap[i] < heap[parentIndex]) {
            swap(heap[i], heap[parentIndex]);
        }
        heapifyUp(parentIndex);
    }
    
    void heapifyDown(int i) {
        // cout<<"I vlaue = "<<i<<endl;
        // cout<<"Element at root now when performing heapify down is = "<<heap[i]<<endl;
        if(i > heap.size()) return;
        int leftChild = 2*i+1;
        int rightChild = 2*i+2;
        if (leftChild > heap.size() || rightChild > heap.size()) return;
        // cout<<"Parent   = "<<i<<" = "<<heap[i]<<endl;
        // cout<<"Left child = "<<leftChild<<" = "<<heap[leftChild]<<endl;
        // cout<<"Right child = "<<rightChild<<" = "<<heap[rightChild]<<endl;
        if (heap[leftChild] <= heap[rightChild]){
            if (heap[leftChild] <= heap[i]){
                swap(heap[leftChild], heap[i]);
                heapifyDown(leftChild);
            }
        } else {
            if (heap[rightChild] <= heap[i]){
                swap(heap[rightChild], heap[i]);
                heapifyDown(rightChild);
            }
        }
        
    }
    
    void insertElement(int x) {
        heap.push_back(x);
        heapifyUp(heap.size()-1);
    }
    
    void deleteElement() {
        if (heap.size() == 0)
            {
            cout<<"Heap mein kuch hai hee nahi"<<endl;
            return;
            }
        heap[0] = heap[heap.size()-1];
        heap.pop_back();
        heapifyDown(0);
    }
    
};


class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        int numberOfElementsInHeap = k;
        if (matrix.size() < k) {
            numberOfElementsInHeap = matrix.size();
        }
        cout<<"Number of elements deserved to be inserted in heap = "<<numberOfElementsInHeap<<endl;
        myMinHeap mp;
        
        for(int i=0; i<numberOfElementsInHeap; i++) {
            for(int j=0; j<numberOfElementsInHeap; j++) {
                mp.insertElement(matrix[i][j]);
            }
        }
//         cout<<"Fine till here - 1"<<endl;
//         cout<<"Printing elements in heap"<<endl;
        
//         for(int i=0; i<mp.heap.size(); i++){
//             cout<<mp.heap[i]<<endl;
//         }
//         cout<<"Deletion starting ... "<<endl;
        int i = 1;
        while(i != k) {
            // cout<<"After "<<i<< "st deletion"<<endl;
            
            mp.deleteElement();
            // for(int i=0; i<mp.heap.size(); i++){
            //     cout<<mp.heap[i]<<endl;
            // }
            // cout<<"at root "<<mp.heap[0]<<endl;
            i++;
        }
        // cout<<mp.heap[0];
        return mp.heap[0];
    }
};
