import DAN

def profile_init():
    DAN.profile['dm_name']='MCU_board'
    DAN.profile['d_name']=DAN.get_mac_addr()[-6:]+'_Yun'


def odf():  # int only
    return [
	('D2', 0, 'D2'),
	('D3', 0, 'D3'),
	('D4', 0, 'D4'),
	('D5', 0, 'D5'),
	('D6', 0, 'D6'),
        ('D7', 0, 'D7'),
        ('D8', 0, 'D8'),
    ]


def idf():
    return [
       ('A0', float),
       ('A1', float),
       ('A2', float),
       ('A3', float),
       ('A4', float),
       ('A5', float),
    ]
