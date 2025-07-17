import pandas as pd

def createDataframe(student_data: List[List[int]]) -> pd.DataFrame:
    names = ['student_id', 'age']
    return pd.DataFrame(student_data, columns=names)
