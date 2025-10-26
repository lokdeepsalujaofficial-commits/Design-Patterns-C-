using RuleEngineLLD.Models;

namespace RuleEngineLLD.Services.Rules;

/// <summary>
/// Interface for rules that validate individual expenses.
/// In C#, interfaces are similar to Java - methods without implementation.
/// Nullable return type (Violation?) is like Java's Optional<Violation>.
/// </summary>
public interface IExpenseRule
{
    /// <summary>
    /// Checks an expense against this rule.
    /// Returns null if no violation, or a Violation object if rule is violated.
    /// </summary>
    Violation? Check(Expense expense);
}

