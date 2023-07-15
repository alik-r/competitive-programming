def hanoi(n: int) -> int:
    if n == 1:
        return 1
    else:
        return 2 * hanoi(n - 1) + 1

def hanoiWithSteps(n, fromRod, toRod, otherRod):
    if n == 0:
        return
    hanoiWithSteps(n - 1, fromRod, otherRod, toRod)
    print(f"Move disk {n} from rod {fromRod} to rod {toRod}")
    hanoiWithSteps(n - 1, otherRod, toRod, fromRod)    

n = int(input("Enter the number of discs: "))
hanoiWithSteps(n, "A", "C", "B")
print(f"Steps to move {n} disc(s) from rod A to rod C: {hanoi(n)}")
