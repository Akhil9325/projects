MOD = 10**9 + 7

def sum_of_digits(n):
    return sum(int(digit) for digit in str(n))

def count_valid_numbers(l, r, k):
    # We need to consider the length of numbers.
    count = 0
    for length in range(l, r + 1):
        # Calculate the range for numbers with this length
        start = 10**(length - 1)
        end = 10**length

        # Iterate over possible digit sums
        for digit_sum in range(1, 9 * length + 1):
            if k * digit_sum < 10 * length and (k * digit_sum) % 9 == digit_sum % 9:
                count += 1

    return count % MOD

def main():
    t = int(input().strip())
    results = []
    for _ in range(t):
        l, r, k = map(int, input().strip().split())
        results.append(count_valid_numbers(l, r, k))
    
    for result in results:
        print(result)

if __name__ == "__main__":
    main()
