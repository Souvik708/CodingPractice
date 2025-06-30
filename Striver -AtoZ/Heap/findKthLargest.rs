use std::collections::BinaryHeap;
use std::cmp::Reverse;

impl Solution {
    pub fn find_kth_largest(nums: Vec<i32>, k: i32) -> i32 {
        let mut minHeap = BinaryHeap::new() ;
        let n = nums.len() ;     
        
        for i in 0..n{
            minHeap.push(Reverse(nums[i])) ;
            if minHeap.len() > k {
                minHeap.pop() ;
            }
        }

        minHeap.peek()
    }
}