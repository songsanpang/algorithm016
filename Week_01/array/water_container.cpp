// //暴力法
// class Solution {
// public:
//     int max_area =0 , area;
//     int maxArea(vector<int>& height) {
//         for(int i =0; i <height.size()-1; ++i ) {
//             for(int j =i+1; j< height.size(); ++j) {
//                 area = ( j-i )* std::min(height[i],height[j]);
//                 maxarea = std::max(maxarea , area);
//             }
//         }
//         return max_area;
//     }
// };




//双指针法
class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area =0,area;
        for(int i =0, j = height.size()-1; i <j; height[i]>height[j]?--j:++i) {
            area=(j-i)*min(height[i],height[j]);
            max_area = max(max_area,area);
        }
        return max_area;
    }
};



