class Solution {
    List<List<Integer>> res = new ArrayList<>();
    List<Integer> list = new ArrayList<>();
    public List<List<Integer>> combinationSum(int[] nums, int target) {
        int start = 0;
        backtrack(start, target, nums);
        return res;
    }
    private void backtrack(int start, int target, int nums[] ){
        if(target == 0){
            res.add(new ArrayList<>(list));
            return;
        }
        if(target <  0) return;

        for(int i = start; i < nums.length; i++){
            list.add(nums[i]);
            backtrack(i, target - nums[i], nums);
            list.remove(list.size()-1);
        }
    }
}