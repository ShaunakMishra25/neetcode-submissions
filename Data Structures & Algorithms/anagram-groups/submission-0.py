from collections import defaultdict
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        ana_map= defaultdict(list)

        for w in strs:
            count=[0]*26
            for c in w:
                count[ord(c)-ord('a')]+=1
            
            key =tuple(count)
            ana_map[key].append(w)
        return list(ana_map.values())