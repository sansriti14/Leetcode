class Solution {
    private boolean check(int[] arr, int index, boolean[] visited) {
        if(index < 0 || index >= arr.length || visited[index] == true) return false;
        if(arr[index] == 0) return true;;
        
        visited[index] = true;
        
        return check(arr, index - arr[index], visited) || check(arr, index + arr[index], visited);
    }
    
    public boolean canReach(int[] arr, int start) {
        int n = arr.length;
        boolean[] visited = new boolean[n];
        return check(arr, start, visited);
    }
}