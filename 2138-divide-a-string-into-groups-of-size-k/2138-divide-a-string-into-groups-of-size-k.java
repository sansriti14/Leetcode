class Solution {
    public String[] divideString(String s, int k, char fill) {
        int n = s.length();
        List<String> ans = new ArrayList<>();

        for (int i = 0; i < n; i += k) {
            StringBuilder str = new StringBuilder();
            for (int j = i; j < i + k && j < n; j++) {
                str.append(s.charAt(j));
            }

            ans.add(str.toString());
        }

        int m = ans.get(ans.size() - 1).length();
        while (m++ < k) {
            ans.set(ans.size() - 1, ans.get(ans.size() - 1) + fill);
        }

        return ans.toArray(new String[0]);
    }
}