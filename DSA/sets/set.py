def setMaker(s):
    ans = Set(0)
    for i in range(len(s)):
        ans.add(s[i])
    return ans

class Set:

    # Constructor
    def __init__(self, initCount):
        self._s = []
        for i in range(initCount):
            data = int(input("Enter Element {} : ".format(i+1)))
            self.add(data)

    # Get Set
    def getSet(self):
        return self._s

    # Size of the set
    def __len__(self):
        return len(self._s)

    # Print Set
    def __str__(self):
        string = "\n{ "
        for i in range(len(self)):
            string += str(self._s[i])
            if i != len(self) - 1:
                string += ' , '
        string += " }\n"
        return string

    # Check if a element is present in a set or not
    def __contain__(self, val):
        return val in self

    # Check if the set is empty or not
    def isEmpty(self):
        return True if len(self) else False

    # Add element in set
    def add(self, val):
        if val not in self._s:  # just self also works if iterator is present
            self._s.append(val)

    # Remove Element from the set
    def remove(self, val):
        if val in self._s:
            self._s.remove(val)

    # Determine if the two sets area equal or not
    def __eq__(self, s):
        if len(self) != len(s):
            return False
        else:
            return self.isSubsetOf(s)

    # Determine if a set if subset of other set
    def isSubsetOf(self, s):
        for i in s:
            if i not in self:
                return False
        return True

    # Determine if a set if proper subset of other set
    def isProperSubset(self, s):
        return self.isSubsetOf(s) and not s.isSubsetOf(self)

    # SetMaker util func
    

    # Union of sets
    def union(self, s):
        ans = []

        for i in self:
            ans.append(i)

        for i in s:
            if i not in ans:
                ans.append(i)
        # a = self.unionUtil(ans)
        return setMaker(ans)

    # Difference of sets
    def difference(self, s):
        ans = []
        for i in self:
            if i not in s:
                ans.append(i)
        return setMaker(ans)

    # Intersection of sets
    def intersect(self, s):
        ans = []
        for i in s:
            if i in self:
                ans.append(i)
        return setMaker(ans)

    # Iterator
    def __iter__(self):
        return iter(self._s)
