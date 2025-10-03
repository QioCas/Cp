# Function to read input data for multiple queries
def read_input(filename="input.txt"):
    with open(filename, 'r') as file:
        Q = int(file.readline())  # Read number of queries
        queries = []
        
        for _ in range(Q):
            # Read the dimensions of the image and kernel
            n, K = map(int, file.readline().split())
            
            # Read image matrix
            image = []
            for _ in range(n):
                image.append(list(map(int, file.readline().split())))
            
            # Read kernel matrix
            kernel = []
            for _ in range(K):
                kernel.append(list(map(int, file.readline().split())))
            
            queries.append((image, kernel))
        
    return queries


# Apply the convolution operation for a sub-matrix
def apply_convolution(image, kernel):
    n = len(image)  # Size of image
    k = len(kernel)  # Size of kernel
    padding = 1
    result = [[0] * n for _ in range(n)]  # Initialize result matrix with zeros
    
    # Apply kernel over the image (sliding window)
    for i in range(0, n):
        for j in range(0, n):
            total = 0
            # Multiply corresponding elements and sum them
            for ki in range(k):
                for kj in range(k):
                    ni, nj = i + ki - padding, j + kj - padding
                    if 0 <= ni < n and 0 <= nj < n and 0 <= ki < k and 0 <= kj < k:
                        total += image[ni][nj] * kernel[ki][kj]
            result[i][j] = total  # Assign computed value to result
    
    return result


# Main function to read from file, process each query, and return results
def MAIN(filename="input.txt"):
    # Read all queries from the input file
    queries = read_input(filename)
    
    results = []
    # Process each query
    for image, kernel in queries:
        # Apply convolution in parallel
        output_image = apply_convolution(image, kernel)
        results.append(output_image)
    
    return results

# To run the function and print the result:
if __name__ == "__main__":
    results = MAIN("input.txt")
    for result in results:
        for row in result:
            print(" ".join(map(str, row)))
        print("++++")