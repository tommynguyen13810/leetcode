/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
 var twoSum = function(nums, target) {
    const map = new Map()
    for(let i = 0; i < nums.length; i++) {
        let value = target - nums[i]
        if(map.get(value) != undefined && map.get(value) != i){
            return [map.get(value), i] 
        }
        map.set(nums[i], i)
    }
};
