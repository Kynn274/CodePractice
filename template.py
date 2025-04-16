import json
import re

sql_schema = """
CREATE database TOWER_DEFENSE_v1
USE TOWER_DEFENSE_v1

CREATE TABLE Accounts(
	Id INT IDENTITY(1,1) NOT NULL,
	Email NVARCHAR(255),
	PasswordHash NVARCHAR(255),
	PRIMARY KEY(Id)
);
GO

CREATE TABLE GameAvatars(
	Id INT IDENTITY(1,1) NOT NULL,
	ImageLink NVARCHAR(255) NOT NULL,
	PRIMARY KEY (Id)
);
GO

CREATE TABLE Players(
	Id INT IDENTITY(1,1) NOT NULL,
	AccountId INT NOT NULL,
	PlayerLevel INT NOT NULL DEFAULT 1,
	PlayerExp INT NOT NULL DEFAULT 0,
	PlayerGold INT NOT NULL DEFAULT 0,
	PlayerName NVARCHAR(255) NOT NULL,
	PlayerAvatar INT NOT NULL,
	PRIMARY KEY(Id),
	FOREIGN KEY (PlayerAvatar) REFERENCES GameAvatars(Id),
	FOREIGN KEY (AccountId) REFERENCES Accounts(Id)
);
GO

CREATE TABLE ItemCategories(
	Id INT IDENTITY(1,1) NOT NULL,
	CategoryName NVARCHAR(255) NOT NULL,
	PRIMARY KEY (Id)
);
GO

CREATE TABLE Items(
	Id INT IDENTITY(1,1) NOT NULL,
	ItemCategoryId INT NOT NULL,
	ItemName NVARCHAR(255) NOT NULL,
	ItemDescription NVARCHAR(2000),
	ItemImage NVARCHAR(1000),
	ItemPrice INT NOT NULL DEFAULT 0,
	ItemCurrencyType INT NOT NULL DEFAULT 1, /* 1: Gold, 2: Diamond */
	PRIMARY KEY (Id),
	FOREIGN KEY (ItemCategoryId) REFERENCES ItemCategories(Id)
);
GO

CREATE TABLE PlayerInventory(
	PlayerId INT IDENTITY(1,1) NOT NULL,
	ItemId INT NOT NULL,
	Quantity INT NOT NULL DEFAULT 0,
	FOREIGN KEY (PlayerId) REFERENCES Players(Id),
	FOREIGN KEY (ItemId) REFERENCES Items(Id)
);
GO

CREATE TABLE Monsters(
	Id INT IDENTITY(1,1) NOT NULL,
	MonsterName NVARCHAR(255) NOT NULL,
	MonsterDescription TEXT,
	MonsterSpeed DECIMAL(10,2) NOT NULL DEFAULT 0,
	MonsterAttackSpeed DECIMAL(10,2) NOT NULL DEFAULT 0,
	MonsterAttackRange DECIMAL(10,2) NOT NULL DEFAULT 0,
	MonsterLevel INT NOT NULL DEFAULT 1,
	MonsterHp INT NOT NULL DEFAULT 0,
	MonsterAttack DECIMAL(10,2) NOT NULL DEFAULT 0,
	MonsterImage NVARCHAR(1000),
	PRIMARY KEY (Id)
);
GO

CREATE TABLE Bosses(
	Id INT IDENTITY(1,1) NOT NULL,
	BossName NVARCHAR(255) NOT NULL,
	BossDescription TEXT,
	BossSpeed DECIMAL(10,2) NOT NULL DEFAULT 0,
	BossAttackSpeed DECIMAL(10,2) NOT NULL DEFAULT 0,
	BossAttackRange DECIMAL(10,2) NOT NULL DEFAULT 0,
	BossLevel INT NOT NULL DEFAULT 1,
	BossHp INT NOT NULL DEFAULT 0,
	BossAttack DECIMAL(10,2) NOT NULL DEFAULT 0,
	BossImage NVARCHAR(1000),
	PRIMARY KEY (Id)
);
GO

CREATE TABLE Stages(
	Id INT IDENTITY(1,1) NOT NULL,
	StageName NVARCHAR(255) NOT NULL,
	StageWaveCount INT NOT NULL DEFAULT 0,
	StageUnlocked INT NOT NULL DEFAULT 0, /* 0: Locked, 1: Unlocked*/
	PRIMARY KEY (Id)
);
GO

CREATE TABLE Waves(
	Id INT IDENTITY(1,1) NOT NULL,
	StageId INT NOT NULL,
	PRIMARY KEY (Id),
	FOREIGN KEY (StageId) REFERENCES Stages(Id)
);
GO

CREATE TABLE WaveMonsters(
	WaveId INT NOT NULL,
	MonsterId INT NOT NULL,
	MonsterNumber INT NOT NULL DEFAULT 0,
	FOREIGN KEY (WaveId) REFERENCES Waves(Id),
	FOREIGN KEY (MonsterId) REFERENCES Monsters(Id)
);
GO

CREATE TABLE WaveBosses(
	WaveId INT NOT NULL,
	BossId INT NOT NULL,
	BossNumber INT NOT NULL DEFAULT 0,
	FOREIGN KEY (WaveId) REFERENCES Waves(Id),
	FOREIGN KEY (BossId) REFERENCES Bosses(Id)
);
GO

CREATE TABLE Plays(
	Id INT IDENTITY(1,1) NOT NULL,
	PlayerId INT NOT NULL,
	StageId INT NOT NULL,
	PlayStar INT NOT NULL DEFAULT 0,
	PRIMARY KEY (Id),
	FOREIGN KEY (PlayerId) REFERENCES Players(Id),
	FOREIGN KEY (StageId) REFERENCES Stages(Id)
);
GO

CREATE TABLE Rewards(
	Id INT IDENTITY(1,1) NOT NULL, 
	RewardName NVARCHAR(255) NOT NULL,
	RewardImage NVARCHAR(1000),
	PRIMARY KEY (Id)
);
GO

CREATE TABLE StageRewards(
	StageId INT NOT NULL,
	RewardId INT NOT NULL,
	RewardNumber INT NOT NULL DEFAULT 0,
	RewardStarCondition INT NOT NULL DEFAULT 1,
	RewardReceived INT NOT NULL DEFAULT 0, /* 0: not received, 1: received*/
	FOREIGN KEY (StageId) REFERENCES Stages(Id),
	FOREIGN KEY (RewardId) REFERENCES Rewards(Id)
);
GO

CREATE TABLE Skills(
	Id INT IDENTITY(1,1) NOT NULL,
	SkillName NVARCHAR(255) NOT NULL,
	SkillImage NVARCHAR(1000),
	SkillBaseDamage DECIMAL(10,2) NOT NULL DEFAULT 0,
	SkillBaseSpeed DECIMAL(10,2) NOT NULL DEFAULT 0,
	SkillAOE DECIMAL(10,2) NOT NULL DEFAULT 0,
	SkillCooldown DECIMAL(10,2) NOT NULL DEFAULT 0, /*second*/
	SkillStun DECIMAL(10,2) NOT NULL DEFAULT 0,
	SkillBasePrice INT NOT NULL DEFAULT 0,
	PRIMARY KEY (Id)
);
GO

CREATE TABLE UpdateSkills(
	SkillId INT NOT NULL,
	PlayerId INT NOT NULL,
	UpdateLevel INT NOT NULL DEFAULT 1,
	UpdateDamage DECIMAL(10,2),
	UpdateSpeed DECIMAL(10,2),
	UpdateAOE DECIMAL(10,2),
	UpdateCooldown DECIMAL(10,2),
	UpdateStun DECIMAL(10,2),
	UpdatePrice INT,
	FOREIGN KEY (SkillId) REFERENCES Skills(Id),
	FOREIGN KEY (PlayerId) REFERENCES Players(Id)
);
GO

CREATE TABLE SpecificSkills(
	Id NVARCHAR(255) NOT NULL,
	SpecificSkillName NVARCHAR(255) NOT NULL,
	SpecificSkillDescription TEXT,
	SpecificSkillEffects NVARCHAR(255),
	SpecificSkillLevelUnlock INT NOT NULL DEFAULT 1,
	PRIMARY KEY (Id)
);
GO

CREATE TABLE Buffs(
	Id INT IDENTITY(1,1) NOT NULL,
	BuffName NVARCHAR(255) NOT NULL,
	PRIMARY KEY (Id)
);
GO

CREATE TABLE SpecificSkillBuffs(
	SpecificSkillId NVARCHAR(255) NOT NULL,
	BuffId INT NOT NULL,
	Amount DECIMAL(10,2) NOT NULL DEFAULT 0,
	FOREIGN KEY (SpecificSkillId) REFERENCES SpecificSkills(Id),
	FOREIGN KEY (BuffId) REFERENCES Buffs(Id)
);
GO

ALTER TABLE SpecificSkills
ADD SkillId INT NOT NULL FOREIGN KEY REFERENCES Skills(Id);
ALTER TABLE Players
ALTER COLUMN PlayerAvatar INT NOT NULL;
ALTER TABLE Players
ADD FOREIGN KEY (PlayerAvatar) REFERENCES GameAvatars(Id);

"""

def sql_to_json(sql):
    tables = []
    current_table = {}
    
    # Split into table definitions
    table_blocks = re.split(r'CREATE TABLE (\w+)', sql)[1:]
    
    for i in range(0, len(table_blocks), 2):
        table_name = table_blocks[i].strip()
        columns_text = table_blocks[i+1]
        
        columns = []
        # Extract columns
        for line in columns_text.split('\n'):
            line = line.strip(' ,')
            if not line or line.startswith('PRIMARY KEY') or line.startswith('FOREIGN KEY'):
                continue
                
            col_match = re.match(r'(\w+)\s+([\w\(\)]+)', line)
            if col_match:
                col_name, col_type = col_match.groups()
                col_data = {
                    "name": col_name,
                    "type": col_type,
                    "nullable": "NOT NULL" in line.upper(),
                    "default": re.search(r'DEFAULT\s+([\w\(\)\']+)', line, re.I).group(1) if "DEFAULT" in line else None,
                    "identity": "IDENTITY" in line.upper(),
                    "primary_key": "PRIMARY KEY" in line.upper()
                }
                columns.append(col_data)
        
        # Create table JSON
        table_json = {
            "table": table_name,
            "columns": columns
        }
        
        with open(f'{table_name}.json', 'w') as f:
            json.dump(table_json, f, indent=2)

sql_to_json(sql_schema)