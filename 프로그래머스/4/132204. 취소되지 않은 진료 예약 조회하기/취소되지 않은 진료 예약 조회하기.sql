SELECT a.APNT_NO, p.PT_NAME, p.PT_NO, a.MCDP_CD, d.DR_NAME, a.APNT_YMD
FROM APPOINTMENT a
INNER JOIN PATIENT p ON p.PT_NO = a.PT_NO
INNER JOIN DOCTOR d ON a.MDDR_ID = d.DR_ID
WHERE DATE_FORMAT(a.APNT_YMD, '%Y-%m-%d') = '2022-04-13'
    AND a.APNT_CNCL_YN = 'N'
    AND d.MCDP_CD = 'CS'
ORDER BY APNT_YMD