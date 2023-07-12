class solution:
    def doUnion(self,a,n,b,m):
        list = []
        for i in range(n):
            list[i] = a[i]
        for j in range(m):
            list.append(b[i])
        length = len(set(list))
        return length
    






