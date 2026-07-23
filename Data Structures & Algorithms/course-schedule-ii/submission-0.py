class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        
        preMap = {i : [] for i in range(numCourses)}

        for crs, pre in prerequisites:
            preMap[crs].append(pre)

        output = []
        visitSet, cycle = set(), set()

        def dfs(crs):
            if crs in cycle:
                return False

            if crs in visitSet:
                return True
            
            cycle.add(crs)

            for pre in preMap[crs]:
                if not dfs(pre) : return False
            
            cycle.remove(crs) 
            visitSet.add(crs)
            output.append(crs)
            return True
        
        for c in range(numCourses):
            if not dfs(c) : return []

        return output
