class Solution {
    public void allSubset(List<List<Integer>> res, List<Integer> temp, int[] nums, int i){

        if(i == nums.length){
            res.add(new ArrayList<>(temp));
            return;
        }
        allSubset(res, temp, nums, i+1);

        temp.add(nums[i]);
        allSubset(res, temp, nums, i+1);
        temp.remove(temp.size() - 1);
    }
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> temp = new ArrayList<>();

        allSubset(res, temp, nums, 0);

        return res;
    }
}
