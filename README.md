# OnlineJudge-C-
OnlineJudge using c++

还有很多接口定义不标准的， 你们要自己改一改。

信息分隔符：       "&&&"
属性分隔符：       ":::"
数组元素分隔符：   "::"
! 如果属性列没有东西 用空格代替
--------------------------------------------------------------------------------
客户端向服务端发送数据：

创建用户       格式：  "create_user:::user_name:::user_nickname:::user_password"
创建用户组     格式：  "create_group:::group_owner:::group_name"
用户组添加成员 格式：  "group_add_user:::user1::user2::user3::user4"
用户组添加比赛 格式：  "group_add_contest:::contest1::contest2::contest3"
创建比赛       格式：  "create_contest:::contest_title:::contest_owner:::contest_group:::contest_start_time:::contest_length:::contest_type:::prob1::prob2::prob3"
提交代码       格式：  "submit_code:::user_id:::problem_id"
比赛中提交代码 格式：  "submit_code_from_contest:::user_id:::problem_id:::contest_id:::code"

--------------------------------------------------------------------------------
服务端向客户端发送数据：

发送用户信息   格式:   "user_id:::user_name:::user_password:::user_nickname:::solved_prob1::solved_prob2:::attemped_prob1::attemped_prob2:::favorite_pro1::favorite_pro2:::owned_group1::owned_group2:::entered_group1::entered_group2:::owned_contest1::owned_contest2:::entered_contest1::entered_contest2:::favorite_user1::favorite_user2&&&user_info2&&&user_info2&&&user_info3"
发送用户组信息 格式:   "group_id:::group_owner:::group_name:::group_memb1::group_memb2:::group_contest1::group_contest2&&&group_info2&&&group_info3"
发送题目信息   格式:   "pro_id:::pro_num:::pro_od:::pro_title:::pro_source:::pro_description&&&pro_info2&&&pro_info3"
发送比赛信息   格式:   "contest_id:::contest_title:::contest_owner:::contest_group:::contest_start_time:::contest_length:::contest_type:::contest_status:::prob1::prob2::prob3&&&contest_info2&&&contest_info3"
进行的比赛信息 格式：  "contest_id:::contest_title:::contest_owner:::contest_group:::contest_start_time:::contest_length:::contest_type:::contest_status:::ICP1::ICP2:::ICU1::ICU2:::ICS1::ICS2"
