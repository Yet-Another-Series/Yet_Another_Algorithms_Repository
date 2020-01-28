mem = dict()
def max_num_drops(e, k):
    """
    e is number of eggs, k is number of floors
    """

    # The problem is ill defined for non-positive numbers of eggs or floors
    if k <= 0 or e <= 0:
        return 0

    # With one floor we must drop one egg on that floor to check if it breaks
    if k == 1:
        return 1

    # With only one egg we must search up from the bottom floor
    if e == 1:
        return k

    # Check for stored solution
    if (e, k) in mem:
        return mem[(e, k)]

    # Simulate dropping egg on every floor to find the best worst case
    result = 1000*k  # Number always larger than the correct answer
    for i in range(1, k+1):
        # Number of drops assuming the egg breaks on floor i
        does_break = 1+max_num_drops(e-1, i-1)
        # Number of drops assuming the egg doesn't breaks on floor i
        doesnt_break = 1+max_num_drops(e, k-i)

        # Worst case implies max of two possibilities
        # The best worst case is the minimum of all of these over all floors
        result = min(result, max(does_break, doesnt_break))

    # Store result
    mem[(e, k)] = result
    return result


if __name__ == '__main__':
    e = int(input('Number of eggs: '))
    f = int(input('Number of floors: '))
    print('Maximum number of egg drops to find critical floor is {}'.format(max_num_drops(e, f)))
