class Solution {
    public int minimumCardPickup(int[] cards) {
        int n = cards.length;
        HashSet<Integer> set = new HashSet<>();
        
        int minCards = n + 1;
        int i = 0, j = 0;
        while(j < n) {
            if(set.contains(cards[j])) {
                minCards = Math.min(minCards, set.size() + 1);
                set.remove(cards[i++]);
            } else {
                set.add(cards[j++]);
            }
        } 
        
        return (minCards == n + 1) ? -1 : minCards;
    }
}
