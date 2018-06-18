-- MySQL dump 10.13  Distrib 5.6.32, for Win32 (AMD64)
--
-- Host: localhost    Database: dianxin
-- ------------------------------------------------------
-- Server version	5.6.32

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES UTF8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Temporary view structure for view `csinfoforuser`
--

DROP TABLE IF EXISTS `csinfoforuser`;
/*!50001 DROP VIEW IF EXISTS `csinfoforuser`*/;
SET @saved_cs_client     = @@character_set_client;
SET character_set_client = utf8;
/*!50001 CREATE VIEW `csinfoforuser` AS SELECT 
 1 AS `CSID`,
 1 AS `CSname`,
 1 AS `rank`,
 1 AS `gender`*/;
SET character_set_client = @saved_cs_client;

--
-- Table structure for table `customerservice`
--

DROP TABLE IF EXISTS `customerservice`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `customerservice` (
  `CSID` int(11) NOT NULL DEFAULT '0',
  `CSname` char(30) DEFAULT NULL,
  `rank` tinyint(4) DEFAULT '0',
  `pwd` char(30) DEFAULT NULL,
  `gender` enum('F','M') DEFAULT NULL,
  `valid` enum('Y','N') DEFAULT 'Y',
  PRIMARY KEY (`CSID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `customerservice`
--

LOCK TABLES `customerservice` WRITE;
/*!40000 ALTER TABLE `customerservice` DISABLE KEYS */;
INSERT INTO `customerservice` VALUES (0,'管理员',0,'adminpassword',NULL,'Y'),(1,'柳翠花',7,'password','F','Y'),(2,'朱肉荣',8,'2','M','Y'),(3,'杨肉串',7,'password','M','N'),(4,'苟不理',7,'password','F','Y'),(5,'金二顺',7,'password','M','Y'),(6,'张三',0,'233','M','Y');
/*!40000 ALTER TABLE `customerservice` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `doneyesno`
--

DROP TABLE IF EXISTS `doneyesno`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `doneyesno` (
  `val` char(1) NOT NULL,
  `description` char(20) DEFAULT NULL,
  PRIMARY KEY (`val`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `doneyesno`
--

LOCK TABLES `doneyesno` WRITE;
/*!40000 ALTER TABLE `doneyesno` DISABLE KEYS */;
INSERT INTO `doneyesno` VALUES ('D','失效'),('N','待处理'),('Y','缴费成功');
/*!40000 ALTER TABLE `doneyesno` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `isdone`
--

DROP TABLE IF EXISTS `isdone`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `isdone` (
  `isDone` char(1) NOT NULL,
  `description` char(20) DEFAULT NULL,
  PRIMARY KEY (`isDone`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `isdone`
--

LOCK TABLES `isdone` WRITE;
/*!40000 ALTER TABLE `isdone` DISABLE KEYS */;
INSERT INTO `isdone` VALUES ('D','失效'),('N','待处理'),('Y','缴费成功');
/*!40000 ALTER TABLE `isdone` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `payment`
--

DROP TABLE IF EXISTS `payment`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `payment` (
  `NO` int(11) NOT NULL AUTO_INCREMENT,
  `uid` char(20) DEFAULT NULL,
  `money` int(11) DEFAULT NULL,
  `paydate` date DEFAULT NULL,
  `CSID` int(11) DEFAULT NULL,
  `svcRank` int(11) DEFAULT NULL,
  `isDone` char(1) DEFAULT 'N',
  PRIMARY KEY (`NO`),
  KEY `isDone` (`isDone`),
  KEY `CSID` (`CSID`),
  CONSTRAINT `payment_ibfk_1` FOREIGN KEY (`isDone`) REFERENCES `isdone` (`isDone`),
  CONSTRAINT `payment_ibfk_2` FOREIGN KEY (`CSID`) REFERENCES `customerservice` (`CSID`)
) ENGINE=InnoDB AUTO_INCREMENT=12 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `payment`
--

LOCK TABLES `payment` WRITE;
/*!40000 ALTER TABLE `payment` DISABLE KEYS */;
INSERT INTO `payment` VALUES (1,'12345678910',50,'2018-01-01',1,8,'Y'),(2,'12345678911',50,'2018-01-02',2,9,'D'),(3,'123',20,'2018-01-01',1,8,'Y'),(4,'123',20,'2018-01-15',2,7,'Y'),(5,'12345678910',30,'2018-01-01',2,8,'D'),(6,'123',100,'2018-06-18',2,8,'Y'),(7,'12345687950',200,'2018-06-18',2,9,'Y'),(8,'12345678910',100,'2018-06-18',1,5,'Y'),(9,'123',-120,'2018-06-18',0,NULL,'Y'),(10,'12345678910',-130,'2018-06-18',0,NULL,'Y'),(11,'12345687950',-375,'2018-06-18',0,NULL,'Y');
/*!40000 ALTER TABLE `payment` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Temporary view structure for view `payrecord`
--

DROP TABLE IF EXISTS `payrecord`;
/*!50001 DROP VIEW IF EXISTS `payrecord`*/;
SET @saved_cs_client     = @@character_set_client;
SET character_set_client = utf8;
/*!50001 CREATE VIEW `payrecord` AS SELECT 
 1 AS `NO`,
 1 AS `uid`,
 1 AS `uname`,
 1 AS `money`,
 1 AS `CSID`,
 1 AS `CSname`,
 1 AS `paydate`,
 1 AS `svcRank`,
 1 AS `isDone`*/;
SET character_set_client = @saved_cs_client;

--
-- Table structure for table `svrmenu`
--

DROP TABLE IF EXISTS `svrmenu`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `svrmenu` (
  `sid` int(11) NOT NULL AUTO_INCREMENT,
  `sname` char(30) DEFAULT NULL,
  `description` char(100) DEFAULT NULL,
  `sprice` int(11) NOT NULL,
  PRIMARY KEY (`sid`)
) ENGINE=InnoDB AUTO_INCREMENT=8 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `svrmenu`
--

LOCK TABLES `svrmenu` WRITE;
/*!40000 ALTER TABLE `svrmenu` DISABLE KEYS */;
INSERT INTO `svrmenu` VALUES (1,'默认空套餐','用户还未订阅电信套餐',0),(2,'地翼学生专享套餐','6M带宽，赠送校园用户专享教学区WiFi时长30h',20),(3,'地翼学生专享套餐','6M带宽，赠送校园用户专享教学区WiFi时长30h',20),(4,'套餐3','12M带宽',25),(5,'套餐4','12M带宽的套餐4,日间流量高峰期限速版',20),(6,'地翼学生豪华套餐','50M带宽,赠送校园用户专享教学区WiFi时长240h',70),(7,'大流量超级套餐','100M带宽,送家用路由器1台',100);
/*!40000 ALTER TABLE `svrmenu` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Temporary view structure for view `tobepro`
--

DROP TABLE IF EXISTS `tobepro`;
/*!50001 DROP VIEW IF EXISTS `tobepro`*/;
SET @saved_cs_client     = @@character_set_client;
SET character_set_client = utf8;
/*!50001 CREATE VIEW `tobepro` AS SELECT 
 1 AS `CSID`,
 1 AS `NO`,
 1 AS `uid`,
 1 AS `uname`,
 1 AS `money`,
 1 AS `paydate`,
 1 AS `isDone`,
 1 AS `description`*/;
SET character_set_client = @saved_cs_client;

--
-- Table structure for table `user`
--

DROP TABLE IF EXISTS `user`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `user` (
  `uid` char(20) NOT NULL DEFAULT '',
  `idType` enum('身份证','护照','其他') DEFAULT '身份证',
  `phone` char(13) NOT NULL,
  `gender` enum('F','M') DEFAULT NULL,
  `uname` char(30) DEFAULT NULL,
  `address` char(100) DEFAULT NULL,
  `sid` int(11) DEFAULT '1',
  `account` int(11) DEFAULT '0',
  `note` char(50) DEFAULT NULL,
  `valid` enum('Y','N') DEFAULT 'N',
  PRIMARY KEY (`uid`),
  KEY `sid` (`sid`),
  CONSTRAINT `user_ibfk_1` FOREIGN KEY (`sid`) REFERENCES `svrmenu` (`sid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `user`
--

LOCK TABLES `user` WRITE;
/*!40000 ALTER TABLE `user` DISABLE KEYS */;
INSERT INTO `user` VALUES ('123','身份证','15817922727','M','123','北京天安门',3,120,NULL,'Y'),('12345678910','身份证','15817929777','F','李小花','沁苑12#122',2,130,NULL,'Y'),('12345678911','身份证','15817929999','F','赵铁柱','沁苑13#133',3,0,NULL,'N'),('12345678912','身份证','15817929199','M','猪肉荣','沁苑13#144',2,0,NULL,'N'),('12345678913','身份证','15817929299','F','南宫狗剩','沁苑13#199',3,0,NULL,'N'),('12345678914','身份证','15817229999','F','旧野源','沁苑12#23',3,0,NULL,'N'),('12345687950','护照','15827929564','F','小鸟游六花','不可视边界线',4,375,NULL,'Y');
/*!40000 ALTER TABLE `user` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Temporary view structure for view `userview`
--

DROP TABLE IF EXISTS `userview`;
/*!50001 DROP VIEW IF EXISTS `userview`*/;
SET @saved_cs_client     = @@character_set_client;
SET character_set_client = utf8;
/*!50001 CREATE VIEW `userview` AS SELECT 
 1 AS `uid`,
 1 AS `idType`,
 1 AS `phone`,
 1 AS `gender`,
 1 AS `uname`,
 1 AS `address`,
 1 AS `sid`,
 1 AS `account`,
 1 AS `note`,
 1 AS `valid`,
 1 AS `sname`,
 1 AS `description`*/;
SET character_set_client = @saved_cs_client;

--
-- Final view structure for view `csinfoforuser`
--

/*!50001 DROP VIEW IF EXISTS `csinfoforuser`*/;
/*!50001 SET @saved_cs_client          = @@character_set_client */;
/*!50001 SET @saved_cs_results         = @@character_set_results */;
/*!50001 SET @saved_col_connection     = @@collation_connection */;
/*!50001 SET character_set_client      = utf8 */;
/*!50001 SET character_set_results     = utf8 */;
/*!50001 SET collation_connection      = utf8_general_ci */;
/*!50001 CREATE ALGORITHM=UNDEFINED */
/*!50013 DEFINER=`dianxin`@`localhost` SQL SECURITY DEFINER */
/*!50001 VIEW `csinfoforuser` AS (select `customerservice`.`CSID` AS `CSID`,`customerservice`.`CSname` AS `CSname`,`customerservice`.`rank` AS `rank`,`customerservice`.`gender` AS `gender` from `customerservice` where ((`customerservice`.`CSID` > 0) and (`customerservice`.`valid` = 'Y'))) */;
/*!50001 SET character_set_client      = @saved_cs_client */;
/*!50001 SET character_set_results     = @saved_cs_results */;
/*!50001 SET collation_connection      = @saved_col_connection */;

--
-- Final view structure for view `payrecord`
--

/*!50001 DROP VIEW IF EXISTS `payrecord`*/;
/*!50001 SET @saved_cs_client          = @@character_set_client */;
/*!50001 SET @saved_cs_results         = @@character_set_results */;
/*!50001 SET @saved_col_connection     = @@collation_connection */;
/*!50001 SET character_set_client      = utf8 */;
/*!50001 SET character_set_results     = utf8 */;
/*!50001 SET collation_connection      = utf8_general_ci */;
/*!50001 CREATE ALGORITHM=UNDEFINED */
/*!50013 DEFINER=`dianxin`@`localhost` SQL SECURITY DEFINER */
/*!50001 VIEW `payrecord` AS (select `payment`.`NO` AS `NO`,`user`.`uid` AS `uid`,`user`.`uname` AS `uname`,`payment`.`money` AS `money`,`customerservice`.`CSID` AS `CSID`,`customerservice`.`CSname` AS `CSname`,`payment`.`paydate` AS `paydate`,`payment`.`svcRank` AS `svcRank`,`payment`.`isDone` AS `isDone` from ((`payment` join `user`) join `customerservice`) where ((`user`.`uid` = `payment`.`uid`) and (`customerservice`.`CSID` = `payment`.`CSID`))) */;
/*!50001 SET character_set_client      = @saved_cs_client */;
/*!50001 SET character_set_results     = @saved_cs_results */;
/*!50001 SET collation_connection      = @saved_col_connection */;

--
-- Final view structure for view `tobepro`
--

/*!50001 DROP VIEW IF EXISTS `tobepro`*/;
/*!50001 SET @saved_cs_client          = @@character_set_client */;
/*!50001 SET @saved_cs_results         = @@character_set_results */;
/*!50001 SET @saved_col_connection     = @@collation_connection */;
/*!50001 SET character_set_client      = utf8 */;
/*!50001 SET character_set_results     = utf8 */;
/*!50001 SET collation_connection      = utf8_general_ci */;
/*!50001 CREATE ALGORITHM=UNDEFINED */
/*!50013 DEFINER=`dianxin`@`localhost` SQL SECURITY DEFINER */
/*!50001 VIEW `tobepro` AS (select `payment`.`CSID` AS `CSID`,`payment`.`NO` AS `NO`,`user`.`uid` AS `uid`,`user`.`uname` AS `uname`,`payment`.`money` AS `money`,`payment`.`paydate` AS `paydate`,`payment`.`isDone` AS `isDone`,`isdone`.`description` AS `description` from ((`payment` join `user`) join `isdone`) where ((`user`.`uid` = `payment`.`uid`) and (`payment`.`isDone` = `isdone`.`isDone`))) */;
/*!50001 SET character_set_client      = @saved_cs_client */;
/*!50001 SET character_set_results     = @saved_cs_results */;
/*!50001 SET collation_connection      = @saved_col_connection */;

--
-- Final view structure for view `userview`
--

/*!50001 DROP VIEW IF EXISTS `userview`*/;
/*!50001 SET @saved_cs_client          = @@character_set_client */;
/*!50001 SET @saved_cs_results         = @@character_set_results */;
/*!50001 SET @saved_col_connection     = @@collation_connection */;
/*!50001 SET character_set_client      = utf8 */;
/*!50001 SET character_set_results     = utf8 */;
/*!50001 SET collation_connection      = utf8_general_ci */;
/*!50001 CREATE ALGORITHM=UNDEFINED */
/*!50013 DEFINER=`dianxin`@`localhost` SQL SECURITY DEFINER */
/*!50001 VIEW `userview` AS (select `user`.`uid` AS `uid`,`user`.`idType` AS `idType`,`user`.`phone` AS `phone`,`user`.`gender` AS `gender`,`user`.`uname` AS `uname`,`user`.`address` AS `address`,`svrmenu`.`sid` AS `sid`,`user`.`account` AS `account`,`user`.`note` AS `note`,`user`.`valid` AS `valid`,`svrmenu`.`sname` AS `sname`,`svrmenu`.`description` AS `description` from (`user` join `svrmenu`) where (`svrmenu`.`sid` = `user`.`sid`)) */;
/*!50001 SET character_set_client      = @saved_cs_client */;
/*!50001 SET character_set_results     = @saved_cs_results */;
/*!50001 SET collation_connection      = @saved_col_connection */;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2018-06-18 19:58:12
