<?php

class Solution {

    /**
     * @param Integer[] $gas
     * @param Integer[] $cost
     * @return Integer
     */
    function canCompleteCircuit($gas, $cost) {
        $n = count($gas);
        $start = 0;
        $totalGas = 0;
        $totalCost = 0;
        $currentGas = 0;
        $i = 0;
        while($i < $n) {
            $totalGas += $gas[$i];
            $totalCost += $cost[$i];
            $currentGas += $gas[$i] - $cost[$i];
            if($currentGas < 0) {
                $start = $i+1;
                $currentGas = 0;
            }
            $i++;
        }
        return ($totalGas >= $totalCost) ? $start : -1;
    }
}
