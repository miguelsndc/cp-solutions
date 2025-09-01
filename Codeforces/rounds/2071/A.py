"""
no draws
two players compete, one spectates
no player can play three times in a row

someone plays twice means sit
if no one plays twice than the winner and the spectator plays and loser spectate    

spectator of the first match can be spectator on the k-th matcht
"""

for _ in range(int(input())):
    k = int(input())
    print("YES" if (k-1)%3 ==0 else "NO")