class Solution:
    def canAliceWin(self, n: int) -> bool:
        stones_to_remove = 10
        alice_turn = True
        
        while n >= stones_to_remove:
            n -= stones_to_remove
            stones_to_remove -= 1
            alice_turn = not alice_turn
            
        # If it is Bob's turn when the loop ends, Bob cannot move, so Alice wins
        return not alice_turn
