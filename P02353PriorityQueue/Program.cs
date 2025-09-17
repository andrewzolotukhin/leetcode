public class FoodRatings {
    private Dictionary<string, (string cuisine, int rating)> foodInfo = new();
    private Dictionary<string, SortedDictionary<(int, string), string>> cuisineFoods = new();

    public FoodRatings(string[] foods, string[] cuisines, int[] ratings) {
        for (int i = 0; i < foods.Length; i++) {
            var food = foods[i];
            var cuisine = cuisines[i];
            var rating = ratings[i];
            foodInfo[food] = (cuisine, rating);

            if (!cuisineFoods.ContainsKey(cuisine)) {
                cuisineFoods[cuisine] = new SortedDictionary<(int, string), string>();
            }

            cuisineFoods[cuisine].Add((-rating, food), food);
        }
    }

    public void ChangeRating(string food, int newRating) {
        var (cuisine, oldRating) = foodInfo[food];
        var foods = cuisineFoods[cuisine];
        foods.Remove((-oldRating, food));
        foods.Add((-newRating, food), food);
        foodInfo[food] = (cuisine, newRating);
    }

    public string HighestRated(string cuisine) {
        return cuisineFoods[cuisine].First().Value;
    }
}

