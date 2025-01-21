import time

def main():
    # Start measuring time
    start_time = time.time()

    count = 0
    for i in range(1000000000):
        count += 1

    # Measure the elapsed time
    end_time = time.time()
    execution_time = end_time - start_time
    print(f"Execution time: {execution_time:.6f} seconds")

if __name__ == "__main__":
    main()
