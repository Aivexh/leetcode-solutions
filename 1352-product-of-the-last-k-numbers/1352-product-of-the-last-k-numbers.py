class ProductOfNumbers:
    def __init__(self):
        # Initialize with 1 to handle full-array product division cleanly
        self.prefix = [1]

    def add(self, num: int) -> None:
        if num == 0:
            # Reset the prefix products since any future product 
            # spanning across this zero will be 0
            self.prefix = [1]
        else:
            self.prefix.append(self.prefix[-1] * num)

    def getProduct(self, k: int) -> int:
        # If k is greater than or equal to the current valid prefix length,
        # it means a 0 was encountered within the last k elements
        if k >= len(self.prefix):
            return 0
        return self.prefix[-1] // self.prefix[-1 - k]



# Your ProductOfNumbers object will be instantiated and called as such:
# obj = ProductOfNumbers()
# obj.add(num)
# param_2 = obj.getProduct(k)