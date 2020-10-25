// class Solution {
// public:
//     vector<int> getLeastNumbers(vector<int>& arr, int k) {
//     }
// };


// 简化版本的大顶堆
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if(k == 0) return vector<int>();
        vector<int> max_heap_vec(arr.begin(), arr.begin()+k);
        buildMaxHeap(max_heap_vec);
        for(int i = k; i<arr.size(); ++i){
            // 出现比堆顶元素小的值, 置换堆顶元素, 并调整堆
            if(arr[i] < max_heap_vec[0]){
                emplacePeek(max_heap_vec, arr[i]);
            }
        }
        return max_heap_vec;
    }
private:
    void buildMaxHeap(vector<int>& v){
        // 所有非叶子节点从后往前依次下沉
        for(int i = (v.size()-1)>>1; i>=0; --i){
            downAdjust(v, i);
        }
    }

    void downAdjust(vector<int>& v, int index){
        int parent = v[index];
        // 左孩子节点索引
        int child_index = 2*index + 1;
        while(child_index < v.size()){
            // 判断是否存在右孩子, 并选出较大的节点
            if(child_index + 1 < v.size() && v[child_index+1] > v[child_index]){
                child_index += 1;
            }
            // 判断父节点和子节点的大小关系
            if(parent >= v[child_index]) break;
            // 较大节点上浮
            v[index] = v[child_index];
            index = child_index;
            child_index = 2*index + 1;
        }
        // 避免重复交换的无用工作
        v[index] = parent;
    }

    void emplacePeek(vector<int>& v, int val){
        v[0] = val;
        downAdjust(v, 0);
    }
};




// //维护容量为k的大顶堆
// class Solution {
//     int n {0};
//     enum {MAXN = 10000};
//     int heap[MAXN];
// public:

//     void push(int val) {
//         heap[n++] = val;
//         int i = n-1,tmp = heap[i];
//         for( ;i !=0 ; ) {
//             if(tmp>heap[(i-1)>>1]) {
//                 heap[i] = heap[(i-1)>>1];//赋值不要搞反
//                 i = (i-1)>>1;
//             // }
//             }else break;
//         }
//         heap[i] = tmp;
//     }

//     int pop() {
//         int res = heap[0];
//         swap(heap[0],heap[--n]);//要仔细检测下标的变化，排错太累了
//         int i = 0,left ,right ,tmp = heap[0];
//         while(true) {
//             left = i<<1|1;
//             right = left+1;
//             if(right < size() && tmp < max(heap[left],heap[right])) {
//                 if(heap[left] > heap[right]) {
//                     heap[i] = heap[left];
//                     i = left;
//                 }else{
//                     heap[i] = heap[right];
//                     i = right;
//                 }
//             }else if(left < size() && tmp < heap[left] ) {
//                 heap[i] = heap[left];
//                 heap[left] =tmp;
//                 break;
//             }else {
//                 heap[i] = tmp;
//                 break;
//             }
//         }
//         return res;
//     }

//     int size () const{
//         return n;       
//     }

//     vector<int> getLeastNumbers(vector<int>& arr, int k) {
//         if(!k) return vector<int>() ;
//         for(auto i : arr) {
//             this->push(i);
//             if(this->size() > k) {
//                 pop();
//             }
//         }
//         return vector<int>(heap,heap+k);
//     }
// };