class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        
        priority_queue<int> priceHeap;
        priority_queue<int> discountHeap;

        for (int price : prices) {
            priceHeap.push(price);
        }

        for (int discount : discounts) {
            discountHeap.push(discount);
        }

        double total = 0;

        while (!priceHeap.empty() && !discountHeap.empty()) {
            
            int price = priceHeap.top();
            priceHeap.pop();

            int discount = discountHeap.top();
            discountHeap.pop();

            total += (double)price * (100 - discount) / 100.0;
        }

        // Remaining prices without discount
        while (!priceHeap.empty()) {
            total += priceHeap.top();
            priceHeap.pop();
        }

        return total;
    }
};