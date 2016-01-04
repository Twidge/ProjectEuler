// Returns the maximum of two elements
template<typename T>
T Max(T const& firstObject, T const& secondObject)
{
	return firstObject >= secondObject ? firstObject : secondObject;
}