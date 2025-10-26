namespace RuleEngineLLD.Services.Rules;

/// <summary>
/// Represents a rule violation.
/// Uses the factory pattern with a private constructor and static factory method.
/// In C#, nullable reference types (Nullable<Violation> or Violation?) are similar to Java's Optional.
/// </summary>
public class Violation
{
    private readonly string _message;

    // Private constructor - can only be called from within this class
    private Violation(string message)
    {
        _message = message;
    }

    // Static factory method - creates and returns a new Violation
    public static Violation Of(string message)
    {
        return new Violation(message);
    }

    public string Message => _message;
}

