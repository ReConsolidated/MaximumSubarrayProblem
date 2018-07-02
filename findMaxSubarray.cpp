struct Subarray
{
	int max_left;
	int max_right;
	int sum;
	Subarray(int mL, int mR, int s)
	{
		max_left = mL;
		max_right = mR;
		sum = s;
	}
	
};

Subarray findMaxCrossingSubarray(int A[], int low, int mid, int high)
{
	int left_sum = std::numeric_limits<int>::max() * -1;
	int sum = 0;
	int max_left = 0;
	for (int i = mid; i >= low; i--)
	{
		sum = sum + A[i];
		if (sum > left_sum)
		{
			left_sum = sum;
			max_left = i;
		}
	}

	int right_sum = std::numeric_limits<int>::max() * -1;
	sum = 0;
	int max_right = 0;
	for (int i = mid+1; i <= high; i++)
	{

		sum = sum + A[i];
		if (sum > right_sum)
		{
			right_sum = sum;
			max_right = i;
		}
	}
	return Subarray(max_left, max_right, left_sum + right_sum);
}

Subarray findMaximumSubarray(int A[], int low, int high)
{
	if (high == low)
		return Subarray(low, high, A[low]);
	int mid = (low + high) / 2;
	Subarray left = findMaximumSubarray(A, low, mid);
	Subarray right = findMaximumSubarray(A, mid + 1, high);
	Subarray cross = findMaxCrossingSubarray(A, low, mid, high);
	if (left.sum >= right.sum && left.sum >= cross.sum)
		return left;
	if (right.sum >= left.sum && right.sum >= cross.sum)
		return right;
	return cross;
}
