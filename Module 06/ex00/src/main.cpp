/* types of casting
 * dynamic_cast
Use dynamic_cast for safe downcasting of polymorphic objects in an inheritance hierarchy (when you have virtual functions).
It ensures the cast is valid at runtime and returns:
- The casted pointer if successful.
- NULL for pointers (or throws bad_cast for references) if the cast fails. 
 * const_cast
Use const_cast to add or remove const and volatile qualifiers from a variable.
It’s often used to modify an object that was passed as const.
 * static_cast
The compiler checks the cast at compile time, it doesn't perform runtime checks
Use static_cast for basic, safe type conversions such as:
Converting between related types (e.g., int to float, pointers of related types).
Downcasting in a class hierarchy (when you're sure of the conversion).
 * reinterpret_cast
Use reinterpret_cast for low-level, unsafe casts that reinterpret the binary representation of one type as another.
Often used for casting pointers or converting between incompatible types.
*/