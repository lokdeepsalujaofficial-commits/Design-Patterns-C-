using RuleEngineLLD.Models;
using RuleEngineLLD.Services.Rules;
using RuleEngineLLD.Utils;

namespace RuleEngineLLD.Services.Rules.Impl;

/// <summary>
/// Rule that checks if the total of all trip expenses exceeds a maximum limit.
/// Implements ITripRule to validate multiple expenses together.
/// </summary>
public class TripTotalMaxRule : ITripRule
{
    private readonly double _maxAmount;

    public TripTotalMaxRule(double maxAmount)
    {
        _maxAmount = maxAmount;
    }

    /// <summary>
    /// Validates that all expenses are from the same trip and total doesn't exceed max.
    /// </summary>
    public Violation? Check(List<Expense> expenses)
    {
        if (!ExpenseUtils.AreAllExpensesOfSameTrip(expenses))
        {
            return Violation.Of("Expenses are not of the same trip");
        }

        double total = 0;
        foreach (var expense in expenses)
        {
            total += expense.AmountUsd;
        }

        if (total > _maxAmount)
        {
            return Violation.Of("Trip total exceeds the maximum amount");
        }

        return null; // No violation
    }
}

