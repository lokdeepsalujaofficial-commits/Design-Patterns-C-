using RuleEngineLLD.Models;

namespace RuleEngineLLD.Services.Rules;

/// <summary>
/// Interface for rules that validate trip-level expenses (multiple expenses).
/// </summary>
public interface ITripRule
{
    /// <summary>
    /// Checks a list of expenses against this trip-level rule.
    /// Returns null if no violation, or a Violation object if rule is violated.
    /// </summary>
    Violation? Check(List<Expense> expenses);
}

