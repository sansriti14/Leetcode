class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        sort(begin(tiles), end(tiles));
        
        int maxTiles = 0;
        int i = 0, j = 0;
        int cover = 0;
        while (i < tiles.size() && maxTiles < carpetLen) {
            if (tiles[j][0] + carpetLen > tiles[i][1]) {
                cover += tiles[i][1] - tiles[i][0] + 1;
                maxTiles = max(maxTiles, cover);
                i++;
            }
            
            else {
                int partial = max(0, tiles[j][0] + carpetLen - tiles[i][0]);
                maxTiles = max(maxTiles, cover + partial);
                cover -= (tiles[j][1] - tiles[j][0] + 1);
                j++;
            }
        }
        
        return maxTiles;
    }
};